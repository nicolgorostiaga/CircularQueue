/****************************************************************************
 Basic Operations:

	constructor: constructs an empty Queue
	empty	   : checks if the Queue is empty
	enqueue    : Inserts an element into the Queue
	front	   : Returns the top queue element
	dequeue	   : deletes the top element from the Queue
	display    : Displays the entire Queue

	Student Name: Nicol Gorostiaga
	Course:1107
****************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef CIRCULARQ_H
#define CIRCULARQ_H

typedef int QueElement;

class CircularQ{

private:
	class Node{
	public:
		QueElement data;
		Node * next;

		Node(QueElement d){
			data = d;
			next = NULL;
		}// end Node Constructor
	};
public:
   
	typedef Node * NodePointer;

	CircularQ(){ last = NULL; }				// Create an empty Q
/*****************************************************************************
Default Constructor creates an empty Queue

Pre: None

Post: An empty Queue is created and the last pointer is initialized to NULL
******************************************************************************/
	
	void display(ostream &out) const;		// Helper method
/*****************************************************************************
Display the entire Queue

Pre: Ostream out is open.

Post: Outputs the contents of the Queue in FIFO order
******************************************************************************/

	CircularQ(const CircularQ &origQ);		// Copy constructor
/*****************************************************************************
Copy Constructor: creates a copy of the original Queue

Pre: Original is the Queue to be copied and is received as a const reference
     parameter

Post: A copy of the original has been constructed
******************************************************************************/

	~CircularQ();							// Destructor
/*****************************************************************************
Destructor: deletes the Queue

Pre: None
     
Post: The queue is destroyed and empty queue is created
******************************************************************************/
	
	CircularQ &operator=(const CircularQ &rhs);
/*****************************************************************************
Overloaded Assignment Operator: Mimics the assignment operator

Pre: Original is the Queue to be copied and is received as a const reference
     parameter

Post: The current Queue is replaced by a copy of the Queue of rhs and 
	  a reference to it is returned.
******************************************************************************/
	
	void enqueue(QueElement item);			// put an item into the Q
/*****************************************************************************
enqueue: Inserts an item into the front of the Queue.

Pre: Queue must exist and the parameter item must be initialized.
  
Post: The item is inserted into the Queue.
	  
******************************************************************************/
	
	QueElement front();
/*****************************************************************************
front: Returns the first item in the queue.

Pre: Queue must exist
  
Post: Either an error message will be displayed if the Queue is empty or
	  the front of the Queue is returned.	  
******************************************************************************/
	
	void dequeue();
/*****************************************************************************
dequeue: Deletes the item located in the front of the Queue.

Pre: Checks to see if the Queue is empty
  
Post: Displays an error message if the Queue is empty otherwise the element
	  at the front of the Queue is deleted.	  
******************************************************************************/

	bool empty(){return last == NULL;}
	/*****************************************************************************
empty: Checks to see if the Queue is empty

Pre: A queue must be created
  
Post: Returns either true if the Queue is empty, false otherwise.
******************************************************************************/
private:

	NodePointer last;

};

ostream &operator<<(ostream& out, const CircularQ &q);
/*****************************************************************************
operator<<: Overloaded operator which allows you to display the contents
			of the entire Queue

Pre: ostream must be opened and the const parameter is passed by reference
  
Post: Calls the method display that displays the entire Queue.
	  
******************************************************************************/
	

#endif