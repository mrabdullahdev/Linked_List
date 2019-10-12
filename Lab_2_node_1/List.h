#pragma once
#include <iostream>
#include "node.h"

using namespace std;
class List
{
	// private members 
	Node* headNode;
	Node* currentNode;
	int size;
public:
	List();
	List(int n);
	// functions for inserting Nodes
	void insert(int n);
	void insertAtBegin(int n);
	void insertAtEnd(int n);
	void insertTo(int n, int position);
	void insertBefore(int n, int dnum);
	void insertAfter(int n, int dnum);
	// functions for moving current Node
	void start();
	void end();
	void moveForward();
	void moveBack();

	void displayList();
	// functions for sorting List
	void ascendingSortingOfList();
	void descendingSortingOfList();
	void revertingList();
	// functions for updating Nodes
	bool updateValue(int presentValue, int newValue);
	bool updateIndex(int n, int index);
	// functions for deleting Nodes
	bool deleteNode(int n);
	bool deleteIndex(int index);

	bool searchValue(int n);
	// function s for returning values
	int sumOfNodesofList();
	int get();
	int getSize();


};

