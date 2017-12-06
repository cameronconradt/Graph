#pragma once
#include "NodePair.h"
#include "Node.h"
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Graph
{
public:
	Graph();
	~Graph();
	Graph* reverse();
	queue<Node*> topological_ordering();
	queue<vector<Node*>> strong_connect();
protected:
	vector<NodePair> edges;

};

