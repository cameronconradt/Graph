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
	queue<vector<Node*>> strong_connect();
	void addpair(NodePair* in);
protected:
	vector<NodePair*> edges;
	set<Node*> allnodes;

};

