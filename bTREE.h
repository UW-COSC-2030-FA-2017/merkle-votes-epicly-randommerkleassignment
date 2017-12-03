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
		bool leaf;
	};
	string entry;
private:
	vector <treeNode> vectorNode;
	treeNode * tree;
	int numberNodes;
	int height;
	vector<string> getData() const;
	void getData(vector<string> &, const treeNode *) const;
	vector<int> getTime() const;
	void getTime(vector<int> &, const treeNode *) const;
	int find2(const string vote, treeNode * subtree, bool found);
public:
	bTREE();
	~bTREE();

	static void destroy(bTREE * & subtree);

	vector <treeNode> * getVec()
	{
		return &vectorNode;
	}
	int dataInserted();
	int numberOfNodes();
	int size(treeNode * subtree);

	int leaves(treeNode * subtree);

	int insert(string, int);

	int find(string vote);

	string locate(string);

	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);
	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
#endif