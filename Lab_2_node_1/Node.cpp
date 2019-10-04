#include "node.h"


// function for setting value of node
void Node::setValue(int v)
{
		value = v;
}

void Node::setNextNode(Node* nn)
{
	nextNode = nn;
}

int Node::getValue()
{
	return value;
}

Node* Node::getNextNode()
{
	return nextNode;
}
