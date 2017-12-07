#pragma once
#include <string>
#include <vector>

using namespace std;
class Node
{
public:
	Node(string name);
	~Node();
	string getname();
	void addchild(Node* node);
	vector<Node*> getchildren();
	bool isparent(Node* parent);
	string top_order(vector<Node*> visited);
	friend bool operator==(const Node lh, const Node rh)
	{
		if (lh.name == rh.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
protected:
	string name;
	vector<Node*> children;
};

