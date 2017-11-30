#pragma once
#include <string>
#include <queue>
using namespace std;

class bTREE
{
	struct treeNode {
		string data;
		int time;
		treeNode * left;
		treeNode * right;
	};
	queue <treeNode> queueNode;

private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need
	string entry;
	treeNode * tree; 

public:
	bTREE();
	~bTREE();

	static void destroy(bTREE * & subtree);

	int dataInserted();
	int numberOfNodes();
	int size();

	int leaves(const bTREE * subtree);

	int insert(string, int);

	int find(string);

	string locate(string);

	unsigned int Hash(string str);


	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
