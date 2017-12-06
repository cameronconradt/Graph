#include "Node.h"



Node::Node(string name)
{
	this->name = name;
}


Node::~Node()
{
}

string Node::getname()
{
	return name;
}
