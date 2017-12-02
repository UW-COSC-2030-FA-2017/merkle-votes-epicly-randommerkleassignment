#include <stdio.h>
#include "pMT.h"
#include <fstream>
#include <iostream>
using namespace std;

int stringToInt(string x)
{
	string s = x;
	stringstream temp(s);
	int y = 0;
	temp >> y;
	return y;
}
int main(int argc, char **argv)
{
	string candidate;
	string timeStamp;
	string voteData1;
	string voteData2;
	ifstream file1;
	ifstream file2;
	pMT vote1(1);
	pMT vote2(2);
	file1.open("test1.txt");
	file2.open("test2.txt");
	if (file1.is_open())
	{
		getline(file1, voteData1);
		voteData1 += '\n';
		while (!file1.eof())
		{
			getline(file1, candidate, '\t');
			getline(file1, timeStamp);
			voteData1 = voteData1 + candidate + '\t' + timeStamp + '\n';
			int time = stringToInt(timeStamp);
			vote1.insert(candidate, time);
		}
	}
	
	/*if (file2.is_open())
	{
		getline(file2, voteData2);
		voteData2 += '\n';
		while (!file2.eof())
		{
			getline(file2, candidate, '\t');
			getline(file2, timeStamp);
			voteData2 = voteData2 + candidate + '\t' + timeStamp + '\n';
			int time = stringToInt(timeStamp);
			vote2.insert(candidate, time);
		}
	}*/
	cout << vote1.getTreeData();
	//if (voteData1 == voteData2)
	//	cout << "Validated";
	//else
	//	cout << "Not Validated";

	while (1 > 0)
	{

	}
	
	return 0;
}
