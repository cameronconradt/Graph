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

void Node::addchild(Node* node)
{
	children.push_back(node);
}

vector<Node*> Node::getchildren()
{
	return children;
}

bool Node::isparent(Node* parent)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (*parent == *(children[i]))
			return true;
	}
	return false;
}

queue<Node*> Node::top_order(vector<Node*>* visited)
{
	queue<Node*> result;
	visited->push_back(this);
	for (int i = 0; i < children.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < visited->size() && !found; j++)
		{
			if (*visited->at(j) == *(children[i]))
				found = true;
		}
		if (!found)
		{
			queue<Node*> returned = children[i]->top_order(visited);
			while (returned.size() != 0)
			{
				result.push(returned.front());
				returned.pop();
			}
		}
	}
	result.push(this);
	return result;
}