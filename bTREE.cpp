#include "bTREE.h"
#include <queue>

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
	: tree(NULL)
{
}

bTREE::~bTREE()
{
	destroy(tree);
}

void bTREE::destroy(bTREE * & subtree)
{
	
}

int bTREE::dataInserted()
{
	return leaves(tree);
}

int bTREE::numberOfNodes()
{
	return size(tree);
}

int bTREE::size()
{
	if (tree == NULL)
	{
		return 0;
	}
	return(size(tree->left) + 1 + size(tree->right));
}

int bTREE::leaves(const bTREE * subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}
	else if ((subtree->left == NULL) && (subtree->right == NULL))
	{
		return 1;
	}
	else
	{
		int count = leaves(subtree->left) + leaves(subtree->right);
		return count;
	}
}

int bTREE::insert(string data, int time)
{
	treeNode * A = new treeNode();
	A->data = data;
	A->time = time;
	A->nodeLeft == NULL;
	A->nodeRight == NULL;
	if (tree == NULL)
	{
		tree = A;
	}
	return 1;
}

int bTREE::find(string)
{
	return 1;
}

string bTREE::locate(string)
{
	return string();
}

unsigned int bTREE::Hash(string str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < str.length(); i++)
	{
		hash = hash * a + (str.length());
		a = a * b;
	}

	return hash;
}

bool operator==(const bTREE & lhs, const bTREE & rhs)
{
	return false;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	return false;
}

std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	// TODO: insert return statement here
	return out;
}
