#include "bTREE.h"
#include <queue>
#include <math.h>
// to_string
//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	tree = NULL;
	int height = 0;
}

bTREE::~bTREE()
{
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

int bTREE::size(treeNode * subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}
	return(size(subtree->left) + 1 + size(subtree->right));
}

int bTREE::leaves(treeNode * subtree)
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
	int operations = 0;
	if (vectorNode.empty())
	{
		treeNode temp;
		temp.data = data;
		temp.time = time;
		temp.leaf = true;
		vectorNode.emplace_back(temp);
		operations += 5;
		return 0;
	}
	int find = -1;
	operations++;
	for (int i = 0; i < vectorNode.size(); i++)
	{
		if (vectorNode[i].leaf == true)
		{
			find = i;
			operations+=3;
			break;
		}
		operations++;
	}
	treeNode temp1;
	temp1.data = vectorNode[find].data;
	temp1.time = vectorNode[find].time;
	temp1.leaf = vectorNode[find].leaf;
	operations += 6;
	
	treeNode temp2;
	temp2.data = data;
	temp2.time = time;
	temp2.leaf = true;
	operations += 3;

	vectorNode.emplace_back(temp1);
	vectorNode.emplace_back(temp2);
	operations += 2;

	vectorNode[find].left = &vectorNode[find * 2 + 1];
	vectorNode[find].right = &vectorNode[find * 2 + 2];
	vectorNode[find].leaf = false;
	operations += 8;

	return operations;
}

int bTREE::find(string vote)
{
	int operations = find2(vote, tree, false);
	return operations;
}


int bTREE::find2(const string vote, treeNode * subtree, bool found)
{
	int operations = 0;
	if (vectorNode.size() == 0)
		return 0;
	
	if (subtree != NULL)
	{
		operations++;
		if (vote != subtree->data)
		{
			if (subtree->left != NULL)
				operations += find2(vote, subtree->left, false);
			if (subtree->right != NULL)
				operations += find2(vote, subtree->right, false);
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

string bTREE::locate(string )
{
	return string();
}


bool operator==(const bTREE & lhs, const bTREE & rhs)
{
	if (lhs.vectorNode.size() > rhs.vectorNode.size())
		return false;
	else if (lhs.vectorNode.size() < rhs.vectorNode.size())
		return false;
	else
	{
		for (int i = 0; i < lhs.vectorNode.size(); i++)
		{
			if (lhs.vectorNode[i].data != rhs.vectorNode[i].data)
				return false;
			if (lhs.vectorNode[i].time != rhs.vectorNode[i].time)
				return false;
		}
	}
	return true;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	if (!(lhs == rhs))
		return true;
	return false;
}


std::ostream & operator<<(std::ostream & out, const bTREE & p)
{
	vector<int> tree_time = p.getTime();
	vector<string> tree_data = p.getData();

	for (int i = 0; i < p.numberNodes; i++) {
		out << "Time: " << tree_time[i]
			<< " :: Vote: " << tree_data[i] << '\n';
	}

	return out;
}

void bTREE::getData(vector<string> & tree_data, const treeNode * subtree) const
{
	if (subtree != NULL)
	{
		tree_data.push_back(subtree->data);
		if (subtree->left != NULL)
		{
			getData(tree_data, subtree->left);
		}
		if (subtree->right != NULL)
		{
			getData(tree_data, subtree->right);
		}
	}

	return;
}

vector<string> bTREE::getData() const
{
	vector<string> tree_data;
	getData(tree_data, tree);

	return tree_data;
}

vector<int> bTREE::getTime() const
{
	vector<int> time;
	getTime(time, tree);

	return time;
}
void bTREE::getTime(vector<int> & tree_time, const treeNode * subtree) const
{
	if (subtree != NULL) {
		tree_time.push_back(subtree->time);
		if (subtree->left != NULL) getTime(tree_time, subtree->left);
		if (subtree->right != NULL) getTime(tree_time, subtree->right);
	}

	return;
}