#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addnode(Node* in)
{
	bool found = false;
	for (int i = 0; i < nodes.size() && !found; i++)
	{
		if (*in == *(nodes[i]))
			found = true;
	}
	if (!found)
		nodes.push_back(in);
}

void Graph::addpair(NodePair* in)
{
	int found = -1;
	for (int i = 0; i < nodes.size() && found == -1; i++)
	{
		if (nodes[i]->getname() == in->geta()->getname())
		{
			found = i;
			for (int j = 0; j < nodes.size(); j++)
			{
				if (*(nodes[j]) == *(in->getb()))
					nodes[i]->addchild(nodes[j]);
			}
			//nodes[i]->addchild(new Node(in->getb()->getname()));
		}
	}
	if (found == -1)
	{
		nodes.push_back(new Node(in->geta()->getname()));
		nodes[nodes.size() - 1]->addchild(new Node(in->getb()->getname()));
	}
}

Graph* Graph::reverse()
{
	Graph* result = new Graph();
	for (int i = 0; i < nodes.size(); i++)
	{
		result->addnode(new Node(nodes[i]->getname()));
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			if (nodes[i]->isparent(nodes[j]))
			{
				result->addpair(new NodePair(nodes[j], nodes[i]));
			}
		}
	}
	return result;
}

queue<Node*> Graph::topological_ordering()
{
	vector<Node*>* visited = new vector<Node*>();
	queue<Node*> result;
	for (int i = 0; i < nodes.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < visited->size() && !found; j++)
		{
			if (*(nodes[i]) == *visited->at(j))
				found = true;
		}
		if (!found)
		{
			queue<Node*> returned = nodes[i]->top_order(visited);
			while (returned.size() != 0)
			{
				visited->push_back(returned.front());
				result.push(returned.front());
				returned.pop();
			}
		}
	}
	return result;
}

queue<queue<Node*>> Graph::strong_connect()
{
	Graph* inverted = this->reverse();
	queue<Node*> top_order_inverted = inverted->topological_ordering();
	queue<queue<Node*>> result;

	vector<Node*>* visited = new vector<Node*>();
	while (top_order_inverted.size() != 0)
	{
		bool found = false;
		for (int i = 0; i < visited->size() && !found; i++)
		{
			if (*(visited->at(i)) == *(top_order_inverted.front()))
			{
				found = true;
				top_order_inverted.pop();
			}
		}
		if (!found)
		{
			result.push(top_order_inverted.front()->top_order(visited));
			top_order_inverted.pop();
		}
	}
	return result;
}
