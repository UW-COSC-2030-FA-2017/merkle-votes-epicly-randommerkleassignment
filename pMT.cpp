#include "pMT.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::sort;
using std::vector;
using std::cout;

pMT::pMT(int hashSelect)
/**
* @brief
* @param hashSelect a number corresponding to the hashfunction to use for this pMT
* @return
*/
{
	selectedHash = hashSelect;
}

pMT::~pMT()
/**
* @brief destructor
* @return nada
*/
{
}

int pMT::insert(string vote, int time)
/**
* @brief insert a vote and time into a leaf node of tree
* @param vote - a string
* @param time - an int representing the time
* @return the number of operations needed to do the insert, -1 if out of memory
*/

{
	int operations = myMerkle.insert(vote, time);
	int hashLoc = -1;
	operations++;
	for (int i = 0; i < (*myMerkle.getVec()).size(); i++)
	{
		if ((*myMerkle.getVec())[i].leaf == false)
		{
			hashLoc = i;
			operations+=2;
		}
		operations++;
	}
	if (hashLoc != -1)
	{
		string left = getHash(selectedHash, (*myMerkle.getVec())[hashLoc].left->data);
		string right = getHash(selectedHash, (*myMerkle.getVec())[hashLoc].right->data);
		(*myMerkle.getVec())[hashLoc].data = getHash(selectedHash, left + right);
		operations += 10;
	}

	return operations;
}

int pMT::find(string vote, int time, int hashSelect)
/**
* @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
* @param vote, a string
* @param time, an int
* @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
* @return 0 if not found, else number of opperations required to find the matching vote
*/
{
	int operations = find2(vote, time, &(*myMerkle.getVec()).front(), false);
	return operations;
}

int pMT::find2(string vote, int time, treeNode * subtree, bool found)
{
	int operations = 0;
	if ((*myMerkle.getVec()).size() == 0)
		return 0;

	if (subtree != NULL)
	{
		operations++;
		if (vote != subtree->data || time != subtree->time)
		{
			if (subtree->left != NULL)
				operations += find2(vote, time, subtree->left, false);
			if (subtree->right != NULL)
				operations += find2(vote, time, subtree->right, false);
		}
		else
			found = true;
		if (found != true)
		{
			operations = 0;
		}
	}
	return operations;
}

int pMT::findHash(string mhash)
/**
* @brief does this hash exist in the tree?
* @param mhash, a string to search for in the tree
* @return 0 if not found, else number of opperations required to find the matching hash
*/
{
	int operations = findHash2(mhash, &(*myMerkle.getVec()).front(), false);
	return operations;
}

int pMT::findHash2(string hash, treeNode * subtree, bool found)
{
	int operations = 0;
	if ((*myMerkle.getVec()).size() == 0)
		return 0;

	if (subtree != NULL)
	{
		operations++;
		if (hash != subtree->data)
		{
			if (subtree->left != NULL)
				operations += findHash2(hash, subtree->left, false);
			if (subtree->right != NULL)
				operations += findHash2(hash, subtree->right, false);
		}
		else
			found = true;
		if (found != true)
		{
			operations = 0;
		}
	}
	return operations;
}


string pMT::locateData(string vote)
/**
* @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param vote, the data to search for
* @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
*/
{
	return myMerkle.locate(vote);
}

string pMT::getHash(int num, string data)
{
	string hashed = "";
	if (num == 1)
		hashed = hash_1(data);
	if (num == 2)
		hashed = hash_2(data);
	if (num == 3)
		hashed = hash_3(data);
	return hashed;
}

string pMT::locateHash(string mhash)
/**
* @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param mhash, the hash to search for
* @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
*/
{
	return myMerkle.locate(mhash);
}

string pMT::locate(string)
{
	return string();
}

string pMT::getTreeData()
{
	if ((*myMerkle.getVec()).size() != 0)
		return(*myMerkle.getVec())[0].data;
	return "";
}



string pMT::hash_1(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int hash = 1315423911;
	unsigned int i = 0;
	const char* str = key.c_str();
	for (i = 0; i < key.length(); i++)
	{
		hash ^= ((hash << 5) + (*str) + (hash >> 2));
	}

	return std::to_string(hash);
}

string pMT::hash_2(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
	const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
	const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
	const unsigned int HighBits =
		(unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;
	unsigned int i = 0;
	const char* str = key.c_str();

	for (i = 0; i < key.length(); ++str, ++i)
	{
		hash = (hash << OneEighth) + (*str);

		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return std::to_string(hash);
}

string pMT::hash_3(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;
	const char* str = key.c_str();

	for (i = 0; i < key.length(); ++str, ++i)
	{
		hash = (hash << 4) + (*str);

		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
		}

		hash &= ~x;
	}

	return std::to_string(hash);
}

bool operator ==(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	if (lhs.myMerkle == rhs.myMerkle)
	{
		return true;
	}
	return false;
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	if (lhs.myMerkle != rhs.myMerkle)
	{
		return true;
	}
	return false;
}

pMT operator ^=(const pMT& lhs, const pMT& rhs)
/**
* @brief XOR between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	if (lhs != rhs)
	{
		return true;
	}
	return false;
}


std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
* @brief Print out a tree
* @param out
* @param p
* @return a tree to the screen
*/
{
	out << p.myMerkle;
	return out;
}


pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
* @brief Where do two trees differ
* @param lhs
* @param rhs
* @return a tree comprised of the right hand side tree nodes that are different from the left
*/
{
	pMT temp(rhs.selectedHash);
	//This part doesn't compile which is why it isn't commented out.
	/*if((*lhs.getVec).size() > (*rhs.getVec).size())
		for (int i = 0; i > (*rhs.getVec).size(); i++)
		{
			if ((*rhs.getVec)[i].data != (*lhs.getVec)[i].data)
				temp.insert((*rhs.getVec)[i].data, (*rhs.getVec)[i].time);
		}
	else
	{
		for (int i = 0; i > (*lhs.getVec).size(); i++)
		{
			if ((*rhs.getVec)[i].data != (*lhs.getVec)[i].data)
				temp.insert((*rhs.getVec)[i].data, (*rhs.getVec)[i].time);
		}
		if ((*lhs.getVec).size() < (*rhs.getVec).size())
			for (int i = (*lhs.getVec).size(); i < (*rhs.getVec).size(); i++)
				temp.insert((*rhs.getVec)[i].data, (*rhs.getVec)[i].time);
	}*/
	return temp;
}