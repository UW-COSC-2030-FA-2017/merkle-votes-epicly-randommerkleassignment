#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
	: tree(NULL)
{
}

bTREE::~bTREE()
{
	
}

void bTREE::destroy(bTREE * & subtree)
{
	if (subtree != NULL)

	{

		destroy(subtree->left);

		destroy(subtree->right);

		delete subtree;

		subtree = NULL;

	}
}

int bTREE::dataInserted()
{
	return 1;
}

int bTREE::numberOfNodes()
{
	return 1;
}

int bTREE::insert(string data, int time)
{
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
