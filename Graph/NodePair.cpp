#include "NodePair.h"



NodePair::NodePair(Node* a, Node* b)
{
	this->a = a;
	this->b = b;
}


NodePair::~NodePair()
{
}

Node* NodePair::geta()
{
	return a;
}

Node* NodePair::getb()
{
	return b;
}
