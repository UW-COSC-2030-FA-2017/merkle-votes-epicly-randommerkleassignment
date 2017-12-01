#include "bTREE.h"
#include <queue>
// to_string
//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	tree == NULL;
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
	if (tree == NULL)
	{
		return 0;
	}
	return(size(tree->left) + 1 + size(tree->right));
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
	treeNode * A = new treeNode();
	A->data = data;
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

int bTREE::find(string data)
{
	bool temp = false;
	return find2(data, tree, temp, true);
}

int bTREE::numOperations()
{
	return numberOfOperations;
}

int bTREE::find2(const string data, treeNode * subtree, bool &temp2, bool)
{
	int temp = 0;
	if (!temp2 && subtree != NULL) {
		temp++;
		if (data != subtree->data) {
			if (subtree->left != NULL) temp += find2(data, subtree->left, temp2, false);
			if (subtree->right != NULL) temp += find2(data, subtree->right, temp2, false);
		}
		else temp2 = true;			
		if (!temp2 && tree) 
		{
			temp = 0;
		}
	}
    return temp;
}

string bTREE::locate(string)
{
	return string();
}


bool operator==(const bTREE & lhs, const bTREE & rhs)
{
	bool result(true);
	if (lhs.numberNodes != rhs.numberNodes) result = false;
	else {
		vector<string> left_data = lhs.getData();
		vector<string> right_data = rhs.getData();
		sort(left_data.begin(), left_data.end());
		sort(right_data.begin(), right_data.end());

		for (int i = 0; i < left_data.size(); i++) {
			if (left_data[i] != right_data[i]) {
				result = false;
				i = left_data.size() - 1;
			}
		}
	}

	return result;
}

bool operator!=(const bTREE & lhs, const bTREE & rhs)
{
	return !(lhs == rhs);
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