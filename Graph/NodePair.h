#pragma once
#include "Node.h"
class NodePair
{
public:
	NodePair(Node* a, Node* b);
	~NodePair();
	NodePair* reverse();
protected:
	Node * a;
	Node* b
};

