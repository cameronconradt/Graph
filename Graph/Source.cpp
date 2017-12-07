#pragma once
#include "Graph.h"
#include "Node.h"
#include "NodePair.h"
#include <vector>
#include <iostream>

using namespace std;

bool test1(vector<NodePair*> nodepairs, vector<Node*> nodes);
bool test2(Graph* graph);
bool test3(Graph* graph);
bool test4(Graph* graph, queue<Node*> expected);
bool test5(Graph* graph, queue<Node*> expected);
bool test6(Graph* graph, queue<Node*> expected);
bool test7(Graph* graph, queue<queue<Node*>> expected);
bool test8(Graph* graph, queue<queue<Node*>> expected);
bool test9(Graph* graph, queue<queue<Node*>> expected);
bool test10(Graph* graph, queue<queue<Node*>> expected);
Graph* addtograph(vector<NodePair*> nodepairs, vector<Node*> nodes);

int main()
{
	Graph* empty = new Graph();
	


	
	queue<queue<Node*>> strong_empty;

	vector<Node*> nodes;
	vector<NodePair*> nodepairs;

	Node* A = new Node("A");
	nodes.push_back(A);
	Node* B = new Node("B");
	nodes.push_back(B);
	Node* C = new Node("C");
	nodes.push_back(C);
	Node* D = new Node("D");
	nodes.push_back(D);
	Graph* no_connections = addtograph(nodepairs, nodes);

	NodePair* ab = new NodePair(A, B);
	NodePair* ba = new NodePair(B, A);
	NodePair* db = new NodePair(D, B);

	nodepairs.push_back(ab);
	nodepairs.push_back(ba);
	nodepairs.push_back(db);

	Graph* normal = addtograph(nodepairs, nodes);

	NodePair* cc = new NodePair(C, C);
	nodepairs.push_back(cc);

	Graph* self_loop = addtograph(nodepairs, nodes);
	
	queue<Node*> top_normal;
	top_normal.push(B);
	top_normal.push(A);
	top_normal.push(C);
	top_normal.push(D);

	queue<Node*> top_self;
	top_self = top_normal;

	queue<Node*> top_rev;
	top_rev.push(D);
	top_rev.push(B);
	top_rev.push(A);
	top_rev.push(C);

	queue<Node*> temp;
	temp.push(D);
	queue<queue<Node*>> strong_normal;
	strong_normal.push(temp);
	temp.pop();
	temp.push(A);
	temp.push(B);
	strong_normal.push(temp);
	temp.pop();
	temp.pop();
	temp.push(C);
	strong_normal.push(temp);
	temp.pop();

	queue<queue<Node*>> strong_self = strong_normal;

	queue<queue<Node*>> strong_conn;

	temp.push(A);
	strong_conn.push(temp);
	temp.pop();
	temp.push(B);
	strong_conn.push(temp);
	temp.pop();
	temp.push(C);
	strong_conn.push(temp);
	temp.pop();
	temp.push(D);
	strong_conn.push(temp);
	temp.pop();

	vector<bool> results;
	if (test1(nodepairs, nodes))
		results.push_back(true);
	else
		results.push_back(false);
	if (test2(normal))
		results.push_back(true);
	else
		results.push_back(false);
	if (test3(self_loop))
		results.push_back(true);
	else
		results.push_back(false);
	if (test4(normal, top_normal))
		results.push_back(true);
	else
		results.push_back(false);
	if (test5(self_loop, top_self))
		results.push_back(true);
	else
		results.push_back(false);
	if (test6(normal, top_rev))
		results.push_back(true);
	else
		results.push_back(false);
	if (test7(normal, strong_normal))
		results.push_back(true);
	else
		results.push_back(false);
	if (test8(self_loop, strong_self))
		results.push_back(true);
	else
		results.push_back(false);
	if (test9(empty, strong_empty))
		results.push_back(true);
	else
		results.push_back(false);
	if (test10(no_connections, strong_conn))
		results.push_back(true);
	else
		results.push_back(false);
	for (int i = 1; i < 11; i++)
	{
		if (results[i - 1])
			cout << "Test " << i << " Succeeded!" << endl;
		else
			cout << "Test " << i << " Failed!" << endl;
	}

	return 0;
}
Graph* addtograph(vector<NodePair*> nodepairs, vector<Node*> nodes)
{
	Graph* result = new Graph();
	for (int i = 0; i < nodes.size(); i++)
	{
		result->addnode(new Node(nodes[i]->getname()));
	}
	for (int i = 0; i < nodepairs.size(); i++)
	{
		result->addpair(nodepairs[i]);
	}
	return result;
}
bool test1(vector<NodePair*> nodepairs, vector<Node*> nodes) // Fill Graph
{
	addtograph(nodepairs, nodes);
	return true;
}
bool test2(Graph* graph) // Reverse
{
	Graph* reverse = graph->reverse();
	if (*graph == *(reverse->reverse()))
		return true;
	else
		return false;
}
bool test3(Graph* graph) // Reverse self-loop 
{
	return test2(graph);
}
bool test4(Graph* graph, queue<Node*> expected) // Topological Ordering
{
	queue<Node*> returned = graph->topological_ordering();
	if (returned.size() != expected.size())
		return false;
	while (returned.size() != 0)
	{
		if (*(returned.front()) != *(expected.front()))
			return false;
		returned.pop();
		expected.pop();
	}
	return true;
}
bool test5(Graph* graph, queue<Node*> expected) //  Topological Ordering self-loop
{
	return test4(graph, expected);
}
bool test6(Graph* graph, queue<Node*> expected) //Topological Ordering reversed graph
{
	Graph* reversed = graph->reverse();
	return test4(reversed, expected);
}
bool test7(Graph* graph, queue<queue<Node*>> expected) // Strong_connect
{
	queue<queue<Node*>> returned = graph->strong_connect();
	if (returned.size() != expected.size())
		return false;
	while (returned.size() != 0)
	{
		if (returned.front().size() != expected.front().size())
			return false;
		while (returned.front().size() != 0)
		{
			if (*(returned.front().front()) != *(expected.front().front()))
				return false;
			returned.front().pop();
			expected.front().pop();
		}
		returned.pop();
		expected.pop();
	}
	return true;
}
bool test8(Graph* graph, queue<queue<Node*>> expected) // Strong_connect self-loop
{
	return test7(graph, expected);
}
bool test9(Graph* graph, queue<queue<Node*>> expected) // strong connect empty graph
{
	return test7(graph, expected);
}
bool test10(Graph* graph, queue<queue<Node*>> expected) //strong connect no connections
{
	return test7(graph, expected);
}