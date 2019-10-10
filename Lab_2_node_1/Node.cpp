#include "node.h"


Node::Node()
{
	Node::value = 0;
	Node::prevNode = 0;
	Node::nextNode = 0;
}

// function for setting value of node
void Node::setValue(int v)
{
	Node::value = v;
}

void Node::setPrevNode(Node* nn)
{
	Node::prevNode = nn;
}

void Node::setNextNode(Node* nn)
{
	Node::nextNode = nn;
}

int Node::getValue()
{
	return Node::value;
}

Node* Node::getPrevNode()
{
	return Node::prevNode;
}

Node* Node::getNextNode()
{
	return Node::nextNode;
}
