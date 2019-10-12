#include "List.h"
#include <iostream>

// Construtor of the class List
List::List()
{
	headNode = 0;
	currentNode = 0;
	size = 0;
}

List::List(int n)
{
	Node* newNode = new Node();
	newNode->setValue(n);
	headNode = currentNode = newNode;
	size = 1;
}

// function for inserting node in the list
void List::insert(int n)
{
	Node* newNode = new Node();
	if (currentNode != 0)
	{
		if (currentNode->getNextNode() != 0)	//When Node is not Last of list
		{
			currentNode->getNextNode()->setPrevNode(newNode);//
		}
			newNode->setNextNode(currentNode->getNextNode());
			newNode->setPrevNode(currentNode);//
			currentNode->setNextNode(newNode);
	}
	// this else will work when adding first node in the list
	else
	{
		headNode = newNode;
	}
	currentNode = newNode;
	currentNode->setValue(n);
	size++;
}

// function to add the node in the beginning of the list
void List::insertAtBegin(int n)
{
	Node* newNode = new Node();
	if (headNode != 0)	// Adding first Node in the List
	{
		headNode->setPrevNode(newNode);//
	}
		newNode->setNextNode(headNode);
		headNode = newNode;
		headNode->setValue(n);
		List::start();
		size++;
	
}

// this function inserts the node at the specific position
void List::insertTo(int n, int position)
{
	List::start();
	for (int i = 2; i < position ; i++)
	{
		List::moveForward();
	}
	List::insert(n);	// calling insert function to insert Node
}
// function to insert Node before certain Node
void List::insertBefore(int n, int dnum)
{
	int f = 0;
	List::start();
	for (int i = 0; i < size; i++)
	{
		if (get() == dnum)
		{
			f = 1;
			if (currentNode == headNode)
				List::insertAtBegin(n);
			else
			{
				List::moveBack();
				List::insert(n);	// calling insert function to insert Node
			}
			break;
		}
		List::moveForward();
	}
	if (f == 0)
		cout << "\nValue did not match any of the Nodes in the List.\n";
}

// function to insert Node after certain Node
void List::insertAfter(int n, int dnum)
{
	int f = 0;
	List::start();
	for (int i = 0; i < size; i++)
	{
		if (get() == dnum)
		{
			f = 1;
			List::insert(n);	// calling insert function to insert Node
			break;
		}
		List::moveForward();
	}
	if (f == 0)
		cout << "\nValue did not match any of the Nodes in the List.\n";
}

// function for inserting Node at the end of the List
void List::insertAtEnd(int n)
{
	List::end();
	List::insert(n);
}

// function to update the value of specific node & to return the status of the updation
bool List::updateValue(int presentValue, int newValue)
{
	List::start();	// calling start function to move currentnode to the begining
	// this loop will end when the currentnode will be pointing the last node
	while (currentNode->getNextNode() != 0)	
	{
		if (currentNode->getValue() == presentValue)	// updating the value of specified node
		{
			currentNode->setValue(newValue);
			return true;
		}
		List::moveForward();
	}
	return false;
}

// function for updating value of Node at specific Index in the List
bool List::updateIndex(int n, int index)
{
	// Checking if index not out of bound
	if (index <= size)
	{
		List::start();
		for (int i = 1; i < index ; i++)
		{
			List::moveForward();
		}
		currentNode->setValue(n);
		return true;
	}
	else
	return false;
}

// function for deleting specific Node from the List
bool List::deleteNode(int n)
{
	
		for (int i = 0; i < size; i++)
		{
			List::moveForward();
			if (List::get() == n)
			{
				Node* newNode = new Node();
				newNode = currentNode;
				if (size == 1)
				{
					List::List();
					
				}
				else
				{
					if (currentNode == headNode)
					{
						headNode = headNode->getNextNode();
						headNode->setPrevNode(0);
						List::start();						
					}
					else
					{
						if (currentNode->getNextNode() == 0)
						{
							List::moveBack();
							currentNode->setNextNode(0);																	
						}
						else
						{
							currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
							currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
							List::moveForward();							
						}
					}
					size--;
				}
				delete newNode;
				return true;
			}
		}
	
	return false;
}

// function for deleting the Node from the Index 
bool List::deleteIndex(int index)
{
	if (size != 1)
	{
		if (index < size)	// Checking of index
		{
			List::start();

			for (int i = 1; i < index; i++)
			{
				List::moveForward();
			}
			Node* newNode = new Node();
			newNode = currentNode;
			if (index == 1)	// For deleting first Node of List
			{
				headNode = headNode->getNextNode();
				currentNode = headNode;//
				headNode->setPrevNode(0);//
			}
			else
			{
				currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());//
				currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());//
				currentNode = currentNode->getNextNode();//
			}

			delete newNode;
			size--;
			return true;
		}
		else if (index == size)	// For deleting last Node of List
		{
			Node* newNode = new Node();
			List::end();
			currentNode = currentNode->getPrevNode();
			currentNode->
			setNextNode(0);
			
			delete newNode;
			size--;
			return true;
		}
		
	}
	// this else will work when List has only one Node
	else
	{
		List::List();
		return true;
	}
	return false;
}

// function to search a value in the List
bool List::searchValue(int n)
{
	List::start();
	for (int i = 1; i < size; i++)
	{
		if (currentNode->getValue() == n)
		{
			return true;
		}
		List::moveForward();
	}
	return false;
}

// this function will return the sum of Nodes of the List
int List::sumOfNodesofList()
{
	
		int sum = 0;
		List::start();
		for (int i = 1; i < size; i++)
		{
			sum += currentNode->getValue();
			if (i != (size - 1))
				List::moveForward();
		}
	return sum;
}

// function for getting value of the current node
int List::get()
{
	return currentNode->getValue();
}

// function for getting the size of List
int List::getSize()
{
	return size;
}

// function for starting the list
void List::start()
{
	currentNode = headNode;
}

// function to move the current Node at the last Node
void List::end()
{
	while (currentNode->getNextNode() != NULL)
	{
		List::moveForward();
	}
}

// function for moving the current node to the next node
void List::moveForward()
{
	// this if will that the currentnode is pointing the last node
	if (currentNode->getNextNode() != 0)
		currentNode = currentNode->getNextNode();
	else
		List::start();
}

// function to move current Node to the previous Node
void List::moveBack()
{
	if (currentNode == headNode)
		List::end();
	else
		currentNode = currentNode->getPrevNode();
}


// function for displaying the values of nodes of list
void List::displayList()
{
	if (headNode == 0)	// In case List is Empty
	{
		cout << "List is Empty.\n";
	}
	// This else will work when List is not Empty
	else
	{
		List::start();
		cout << "Values of nodes of List are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << List::get() << endl;
			if (i < (size - 1))
			{
				List::moveForward();
			}
		}
	}
	
	
}
// function for sorting Nodes of List in ascending order
void List::ascendingSortingOfList()
{
	int temp;
	List::start();
	Node* ptr = new Node;
	for (int i = 0; i < size; i++)
	{
		ptr = currentNode->getNextNode();
		for (int j = i + 1; j < size; j++)	
		{
			if (currentNode->getValue() > ptr->getValue())
			{
				temp = currentNode->getValue();
				currentNode->setValue(ptr->getValue());
				ptr->setValue(temp);
			}
			ptr = ptr->getNextNode();
		}
		List::moveForward();
	}
}

// function for sorting Nodes of List in ascending order
void List::descendingSortingOfList()
{
	int temp;
	List::start();
	Node* ptr = new Node;
	for (int i = 0; i < size; i++)
	{
		ptr = currentNode->getNextNode();
		for (int j = i + 1; j < size; j++)
		{
			if (currentNode->getValue() < ptr->getValue())
			{
				temp = currentNode->getValue();
				currentNode->setValue(ptr->getValue());
				ptr->setValue(temp);
			}
			ptr = ptr->getNextNode();
		}
		List::moveForward();
	}
}

// function for reversing Nodes of List
void List::revertingList()
{
	Node* ptr;
	ptr = headNode;
	int dSize = size / 2;
	int temp;
	List::end();	
	for (int i = 0; i < dSize; i++)
	{
		temp = currentNode->getValue();
		currentNode->setValue(ptr->getValue());
		ptr->setValue(temp);
		List::moveBack();
		ptr = ptr->getNextNode();
	}
	List::start();
}

// Destructor
List::~List()
{
	for (int i = 0; i < size; i++)
	{
		Node* newNode = new Node();
		newNode = currentNode;
		delete newNode;
		List::moveForward();
	}
}