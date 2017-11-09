#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
	return 0;
}

int bTREE::numberOfNodes()
{
	return 0;
}

bool bTREE::insert(string data, int time)
{
	return false;
}

bool bTREE::find(string)
{
	return false;
}

string bTREE::locate(string)
{
	return NULL;
}

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	return false;
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	return false;
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	return out;
}