#pragma once
#include "NodePair.h"
#include "Node.h"
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;


class Graph
{
public:
	Graph();
	~Graph();
	Graph* reverse();
	queue<Node*> topological_ordering();
	queue<queue<Node*>> strong_connect();
	void addnode(Node* in);
	void addpair(NodePair* in);
	friend bool operator==(const Graph lh, const Graph rh)
	{
		if (lh.nodes.size() != rh.nodes.size())
			return false;
		for (int i = 0; i < lh.nodes.size(); i++)
		{
			if (*(lh.nodes[i]) != *(rh.nodes[i]))
				return false;
		}
		return true;
	}
protected:
	vector<Node*> nodes;

};

