#pragma once
#include <string>

using namespace std;
class Node
{
public:
	Node(string name);
	~Node();
	string getname();
protected:
	string name;
};

