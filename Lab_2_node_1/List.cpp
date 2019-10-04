#include "List.h"
#include <iostream>

// Construtor of the class List
List::List()
{
	headNode = 0;
	currentNode = 0;
	lastCurrentNode = 0;
	size = 0;
}

// function for inserting node in the list
void List::insert(int n)
{
	
	if (currentNode != 0)
	{
		if (currentNode->getNextNode() == 0)	//Adding node at the end of list
		{
			List::insertAtEnd(n);
		}
		// this else will work when newnode is to be added between two existing nodes
		else
		{
			Node* newNode = new Node();
			newNode->setNextNode(currentNode->getNextNode());
			currentNode->setNextNode(newNode);
			lastCurrentNode = currentNode;
			currentNode = newNode;
			currentNode->setValue(n);
			size++;
		}
		
	}
	// this else will work when adding first node in the list
	else
	{
		List::insertAtEnd(n);
	}
	
}

// function to add the node in the beginning of the list
void List::insertAtBegin(int n)
{
	if (headNode == 0)	// Adding first Node in the List
	{
		List::insertAtEnd(n);
	}
	// This else will work when List is not empty
	else
	{
		Node* newNode = new Node();
		newNode->setNextNode(headNode);
		headNode = newNode;
		headNode->setValue(n);
		List::start();
		size++;
	}
	
}

// function for inserting Node at the end of the List
void List::insertAtEnd(int n)
{
	Node* newNode = new Node();
	if (headNode == 0)	// Adding first Node in the List
	{
		headNode = newNode;
		headNode->setNextNode(0);
		headNode->setValue(n);
		List::start();
	}
	// This else will work when the List is not Empty
	else
	{
		// In case Current Node is not at the last of the List
		while (currentNode->getNextNode() != 0)
		{
			List::move();
		}
		lastCurrentNode = currentNode;
		currentNode->setNextNode(newNode);
		currentNode = newNode;
		currentNode->setValue(n);
		currentNode->setNextNode(0);
	}
	size++;
	
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
		List::move();
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
			List::move();
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
	if (size != 1)
	{
		List::start();
		for (int i = 0; i < size; i++)	// This for loop will go through the List untill it finds the required value
		{
			if (currentNode->getValue() == n)	// In case node is found to be deleted
			{
				Node* newNode = new Node();
				newNode = currentNode;
				if (currentNode->getNextNode() == 0)	// this if will work when the Node to be deleted is last Node
				{

					List::start();
					for (int j = 0; j < size - 2; j++)
					{
						List::move();
					}
					currentNode->setNextNode(0);
				}
				else if (currentNode == headNode)
				{
					headNode = headNode->getNextNode();
					lastCurrentNode->setNextNode(currentNode);
					currentNode = headNode->getNextNode();
				}
				// This else will work when Node to be deleted is not last Node of List
				else
				{
					currentNode = currentNode->getNextNode();
					lastCurrentNode->setNextNode(currentNode);

				}
				delete newNode;
				size--;
				return true;
			}
			List::move();
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
				List::move();
			}
			Node* newNode = new Node();
			newNode = currentNode;
			if (index == 1)	// For deleting first Node of List
			{
				headNode = currentNode->getNextNode();
			}
			currentNode = currentNode->getNextNode();
			lastCurrentNode->setNextNode(currentNode);
			delete newNode;
			size--;
			return true;
		}
		else if (index == size)	// For deleting last Node of List
		{
			Node* newNode = new Node();
			List::start();
			for (int i = 1; i < size - 2; i++)
			{
				List::move();
			}
			currentNode->setNextNode(0);
			delete newNode;
			size--;
			return true;
		}
	}
	// this else will work when List has only one Node
	else
	{
		List::List();
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
		List::move();
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
				List::move();
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
	lastCurrentNode = 0;
	currentNode = headNode;
}

// function for moving the current node to the next node
void List::move()
{
	// this if will that the currentnode is pointing the last node
	if (currentNode->getNextNode() != 0)
	{
		lastCurrentNode = currentNode;
		currentNode = currentNode->getNextNode();
	}
	else
	{
		List::start();
	}
	
}

// this function inserts the node at the specific position
void List::insertTo(int n, int position)
{
	
	if (position == size + 1)	// Adding newnode at the end of list
	{
		List::insertAtEnd(n);
	}
	// this else will work if the newnode is to be added in the between two nodes
	else
	{
		List::start();
		for (int i = 0; i < position - 2; i++)
		{
			List::move();
		}
		List::insert(n);
	}
}

// function to insert Node after certain Node
void List::insertAfter(int n, int value)
{
	int f = 0;
	List::start();
		for (int i = 1; i < size; i++)
		{
			if (currentNode->getValue() == value)
			{
				f = 1;
				Node* newNode = new Node();
				newNode->setNextNode(currentNode->getNextNode());
				currentNode->setNextNode(newNode);
				lastCurrentNode = currentNode;
				currentNode = newNode;
				currentNode->setValue(n);
				size++;
				break;
			}
			List::move();
		}
		if (f == 0)
			cout << "\nValue did not match ant of the Nodes in the List.\n";
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
		for (int i = 0; i < size-1; i++)
		{
			cout << List::get() << endl;
			if (i < (size - 1))
			{
				List::move();
			}
		}
	}
	
	
}
