#include "node.h"


Node::Node()
{
	value = 0;
	prevNode = nextNode = 0;
}

// function for setting value of node
void Node::setValue(int v)
{
		value = v;
}

void Node::setPrevNode(Node* nn)
{
	prevNode = nn;
}

void Node::setNextNode(Node* nn)
{
	nextNode = nn;
}

int Node::getValue()
{
	return value;
}

Node* Node::getPrevNode()
{
	return prevNode;
}

Node* Node::getNextNode()
{
	return nextNode;
}
