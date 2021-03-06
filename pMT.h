#pragma once
#ifndef PMT_H
#define PMT_H
#include "bTREE.h"
#include <string>
#include <sstream>
using namespace std;
using std::string;
class pMT : public bTREE
{
private:
	int selectedHash;
	bTREE myMerkle;

	string hash_1(string);
	string hash_2(string);
	string hash_3(string);
	int find2(string vote, int time, treeNode * subtree, bool found);
	int findHash2(string hash, treeNode * subtree, bool found);

public:
	pMT(int);
	~pMT();

	int insert(string, int);

	int find(string vote, int time, int hashSelect);
	int findHash(string);
	

	string locateData(string vote);
	string getHash(int num, string data);
	string locateHash(string mhash);
	string locate(string);
	string getTreeData();
	friend bool operator==(const pMT& lhs, const pMT& rhs);

	friend bool operator!=(const pMT& lhs, const pMT& rhs);

	friend pMT operator^(const pMT& lhs, const pMT& rhs);
	friend std::ostream& operator<<(std::ostream& out, const pMT& p);

};

#endif