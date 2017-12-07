#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addpair(NodePair* in)
{
	int found = -1;
	for (int i = 0; i < nodes.size() && found == -1; i++)
	{
		if (nodes[i] == in->geta())
		{
			found = i;
			nodes[i]->addchild(new Node(in->getb()->getname()));
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
	vector<Node*> visited;
	queue<Node*> result;
	for (int i = 0; i < nodes.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < visited.size() && !found; j++)
		{
			if (nodes[i] == visited[j])
				found = true;
		}
		if (!found)
		{
			queue<Node*> returned = nodes[i]->top_order(visited);
			while (returned.size() != 0)
			{
				visited.push_back(returned.front());
				result.push(returned.front());
				returned.pop();
			}
		}
	}
}

queue<vector<Node*>> Graph::strong_connect()
{

}
