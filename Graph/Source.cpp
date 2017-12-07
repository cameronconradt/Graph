#pragma once
#include "Graph.h"
#include "Node.h"
#include "NodePair.h"
#include <vector>

using namespace std;

bool test1(vector<NodePair*> nodes);
bool test2(Table* table1, Table* table2, int columns);
bool test3(Table* table1, Table* table2, int rows);
bool test4(Table* table);
bool test5(Table* table1, Table* table2);
bool test6(Table* table);
bool test7(Table* table);
bool test8(Table* table1, Table* table2, int columns);
bool test9(Table* table);
bool test10(Table* table1, Table* table2);
void addtovector(vector<vector<String>> &vec, String str1, String str2);

int main()
{

	vector<bool> results;
	if (test1(tables[0], tables[1]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test2(tables[0], tables[1], 3))
		results.push_back(true);
	else
		results.push_back(false);
	if (test3(tables[0], tables[1], 8))
		results.push_back(true);
	else
		results.push_back(false);
	if (test4(tables[2]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test5(tables[0], tables[3]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test6(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test7(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test8(tables[3], tables[4], 6))
		results.push_back(true);
	else
		results.push_back(false);
	if (test9(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test10(tables[0], tables[3]))
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
		result->addnode(nodes[i]);
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
	if (graph == reverse->reverse())
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
		if (returned.front() != expected.front())
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
			if (returned.front().front() != expected.front().front())
				return false;
			returned.front().pop();
			expected.front().pop();
		}
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