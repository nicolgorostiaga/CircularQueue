#include <iostream>
#include <iomanip>
#include "circq.h"
using namespace std;

template <typename QueElement>
void CircularQ<QueElement>::display(ostream &out) const{
			
	NodePointer first;			// Need a pointer
	
	if (last == NULL)
		cout << "Queue is empty \n\n" ;
	else{
	
		first = last->next;					// no, intialize to first item in the list
		do{
			out << first->data << "  ";		// output the item
			first = first->next;			// move along
		}while(first != last->next);		// have we traversed the entire list?
	}// end else
     
	
}//display method
template <typename QueElement>
CircularQ<QueElement>::~CircularQ(){
	
	NodePointer first;
     
	if(last != NULL){					// empty list?
		first = last->next;				// no, intialize to first item in the list
		while(first != last){
			last->next = first -> next; // avoid memory leak
     		delete first;				// get rid of first node	
			first = last->next;			// adjust to the first node.
		}
		delete first;					// make sure the last node is gone
		last = NULL;					// set to an empty list
	}// end if
	cout << "Exiting Destructor " << endl;

}// end destructor
template <typename QueElement>
void CircularQ<QueElement>::enqueue(QueElement item){
	
	NodePointer newNode = new Node(item);		// Need a node for the Q
     
	if(last == NULL){				    // empty Q
		last = newNode;					// start constructing the Q
		last->next = last;		        // pointer to itself since one item
     }
     else{
		newNode->next = last->next;		// Chain it 
        last->next = newNode;
        last = newNode;
     }
}// end enqueue
template <typename QueElement>
CircularQ<QueElement>::CircularQ(const CircularQ<QueElement> &origQ){ // Copy constructor

	if(origQ.last != NULL){					// empty? 

		NodePointer origLast = origQ.last,		// No. Create pointers to traverse Q's
					origFirst = origLast->next,
					newNode;

		last = new Node(origFirst->data);	// Initialize the new list
		last->next = last;					// set up the correct pointers

		origFirst = origFirst ->next;		// Move to the next item in the list to copy

		while(origFirst != origLast->next){	// Start traversing

			newNode = new Node(origFirst->data);	// create a new new node
			newNode->next = last -> next;			// Start chaining it together
			last->next = newNode;
			last = newNode;
			origFirst = origFirst ->next;			// go to the next one
		}// end while

	}// end if
}//end copy constructor
template <typename QueElement>
CircularQ &CircularQ<QueElement>::operator=(const CircularQ<QueElement> &rhs){

	if(this != &rhs){				// Self-referential Assignment?

		this->~CircularQ();			// No. Destoy LHS 

		if(rhs.last != NULL){		// rhs empty? 

			NodePointer rhsLast = rhs.last,		// Create pointers for traversal
						rhsFirst = rhsLast->next,
						newNode;

			last = new Node(rhsFirst->data);	// Initialize the new LHS
			last->next = last;

			rhsFirst = rhsFirst ->next;			// go to the next RHS item

			while(rhsFirst != rhsLast->next){	// Start traversing

				newNode = new Node(rhsFirst->data);	// Start the process of duplication
				newNode->next = last -> next;
				last->next = newNode;
				last = newNode;
				rhsFirst = rhsFirst ->next;			// Go the next item in the RHS
			}// end while

		}// end if
	}

	return *this;									// Allow assignment chaining

}// end assignment operator

template <typename QueElement>
QueElement CircularQ<QueElement>::front(){

	QueElement garbage = -9999999999999999;
	
	if(empty()){
		cout << "Queue is empty returning garbage" << endl;
		return garbage;
	}
	NodePointer first = last->next;
	return (first->data);

}// return front of Q

template <typename QueElement>
void CircularQ<QueElement>::dequeue(){

	if(empty())
		cout << "Error ----- Cannot delete an item from an empty Queue" 
			 << endl << endl;
	else{

		NodePointer first = last->next;
		if(first == last)
			last = NULL;			// Queue will be empty
		else
			last->next = first->next;
		

		delete first;				// eliminate the node
	}
}// end dequeue
template <typename QueElement>
ostream &operator<<(ostream& out, const CircularQ<QueElement> &q){
	q.display(out);
	return out;
}// end operator<<