#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addpair(NodePair* in)
{
	edges.push_back(in);
}

Graph* Graph::reverse()
{
	Graph* result = new Graph();
	for (int i = 0; i < edges.size(); i++)
	{
		result->addpair(edges[i]->reverse());
	}
	return result;
}

queue<Node*> Graph::topological_ordering()
{

}

queue<vector<Node*>> Graph::strong_connect()
{

}
