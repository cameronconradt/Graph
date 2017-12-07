#pragma once
#include "Node.h"
class NodePair
{
public:
	NodePair(Node* a, Node* b);
	~NodePair();
	Node* geta();
	Node* getb();

protected:
	Node * a;
	Node* b
};

