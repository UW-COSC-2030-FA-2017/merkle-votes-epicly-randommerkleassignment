#include "pMT.h"
#include <vector>
#include <iostream>
#include <algorithm>

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
	treeNode * A = new treeNode();
	A->data = vote;
	A->time = time;
	A->left == NULL;
	A->right == NULL;
	if (tree == NULL)
	{
		tree = A;
		queueNode.push(A);
	}
	else if (queueNode.front()->left == NULL)
	{
		queueNode.front()->left == A;
		queueNode.push(A);
	}
	else if (queueNode.front()->right == NULL)
	{
		queueNode.front()->right == A;
		queueNode.push(A);
		queueNode.pop();
	}
	return 1;
}

int pMT::find(string data)
/**
* @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
* @param vote, a string
* @param time, an int
* @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
* @return 0 if not found, else number of opperations required to find the matching vote
*/
{
	return find(data);
}

int pMT::findHash(string mhash)
/**
* @brief does this hash exist in the tree?
* @param mhash, a string to search for in the tree
* @return 0 if not found, else number of opperations required to find the matching hash
*/
{
	return find(mhash);
}


string pMT::locateData(string vote)
/**
* @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param vote, the data to search for
* @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
*/
{
	return locate(vote);
}

string pMT::locateHash(string mhash)
/**
* @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param mhash, the hash to search for
* @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
*/
{
	return locate(mhash);
}

string pMT::locate(string)
{
	return string();
}

string pMT::getTreeData()
{
	if (tree != NULL)
	{
		return tree->data;
	}
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

	return intToHex(hash);
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

	return intToHex(hash);
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

	return intToHex(hash);
}

bool operator ==(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	return operator==(lhs, rhs);
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	return operator!=(lhs, rhs);
}

pMT operator ^=(const pMT& lhs, const pMT& rhs)
/**
* @brief XOR between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	return operator^=(lhs, rhs);
}


std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
* @brief Print out a tree
* @param out
* @param p
* @return a tree to the screen
*/
{
	return operator<<(out, p);
}


pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
* @brief Where do two trees differ
* @param lhs
* @param rhs
* @return a tree comprised of the right hand side tree nodes that are different from the left
*/
{
	return operator^(lhs, rhs);
}