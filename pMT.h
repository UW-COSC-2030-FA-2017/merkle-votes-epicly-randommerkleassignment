#pragma once
#ifndef PMT_H
#define PMT_H
#include "bTREE.h"
#include <string>
using namespace std;
class pMT : public bTREE
{
private:
	int selectedHash;
	bTREE myMerkle;

	string hash_1(string);
	string hash_2(string);
	string hash_3(string);
	template< typename T >
	std::string intToHex(T i)
	{
		std::stringstream stream;
		stream << "0x"
			<< std::setfill('0') << std::setw(sizeof(T) * 2)
			<< std::hex << i;
		return stream.str();
	}


public:
	pMT(int);
	~pMT();

	bTREE myMerkle;
	int insert(string, int);

	int find(string);
	int findHash(string);

	string locateData(string vote);

	string locateHash(string mhash);

	string locate(string);

	friend bool operator==(const pMT& lhs, const pMT& rhs);

	friend bool operator!=(const pMT& lhs, const pMT& rhs);

	friend pMT operator^(const pMT& lhs, const pMT& rhs);
	friend std::ostream& operator<<(std::ostream& out, const pMT& p);

};

#endif
