#pragma once
class Node
{
	int value;
	Node* nextNode;
public:
	void setValue(int v);
	void setNextNode(Node* nn);
	int getValue();
	Node* getNextNode();
	
};

