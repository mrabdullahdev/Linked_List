#pragma once
class Node
{
	int value;
	Node* prevNode;
	Node* nextNode;
public:
	Node();
	void setValue(int v);
	void setPrevNode(Node* nn);
	void setNextNode(Node* nn);
	int getValue();
	Node* getPrevNode();
	Node* getNextNode();
	
};

