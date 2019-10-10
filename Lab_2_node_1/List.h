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

	void insert(int n);
	void insertAtBegin(int n);
	void insertAtEnd(int n);
	void start();
	void end();
	void moveForward();
	void moveBack();
	void insertTo(int n, int position);
	void insertAfter(int n, int value);
	void displayList();
	void ascendingSortingOfList();
	void descendingSortingOfList();
	void revertingList();

	bool updateValue(int presentValue, int newValue);
	bool updateIndex(int n, int index);
	bool deleteNode(int n);
	bool deleteIndex(int index);
	bool searchValue(int n);

	int sumOfNodesofList();
	int get();
	int getSize();


};

