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
		if (parent == children[i])
			return true;
	}
	return false;
}

string Node::top_order(vector<Node*> visited)
{
	string result = "";
	visited.push_back(this);
	for (int i = 0; i < children.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < visited.size() && !found; j++)
		{
			if (visited[j] == children[i])
				found = true;
		}
		if (!found)
		{
			result += children[i]->top_order(visited);
		}
	}
	result += name;
	return result;
}