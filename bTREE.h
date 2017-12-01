#pragma once
#ifndef BTREE_H
#define BTREE_H
#include <string>
#include <queue>
using namespace std;

class bTREE
{
protected:
	struct treeNode {
		string data;
		int time;
		treeNode * left;
		treeNode * right;
	};
	
	queue <treeNode*> queueNode;
    treeNode * tree;
	string entry;
private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need
	
	
	int numberNodes;
	int height;
	int numberOfOperations;
	vector<string> getData() const;
	void getData(vector<string> &, const treeNode *) const;
	vector<int> getTime() const;
	void getTime(vector<int> &, const treeNode *) const;
public:
	bTREE();
	~bTREE();

	static void destroy(bTREE * & subtree);

	int dataInserted();
	int numberOfNodes();
	int size(treeNode * subtree);

	int leaves(treeNode * subtree);

	int insert(string, int);

	int find(string);

	int numOperations();

	int find2(const string data, treeNode * subtree, bool & temp2, bool);

	string locate(string);

	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
#endif