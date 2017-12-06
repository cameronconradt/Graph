#include "NodePair.h"



NodePair::NodePair(Node* a, Node* b)
{
	this->a = a;
	this->b = b;
}


NodePair::~NodePair()
{
}

NodePair* NodePair::reverse()
{
	NodePair* result = new NodePair(b, a);
	return result;
}
