#pragma once
#include "BitString.h"
#include <iostream>

using namespace std;

class SetClose :
    private BitString
{
public:
	SetClose();
	SetClose(const SetClose& s);

	SetClose& operator=(const SetClose& s);
	SetClose& operator=(const BitString& s);

	friend ostream& operator << (ostream& out, SetClose& s);
	friend istream& operator >> (istream& in, SetClose& s);

	using BitString::operator std::string;
	using BitString::Read;
	using BitString::Display;
	using BitString::Init;
	using BitString::toString;

	void Exclude(int pos);
	void Include(int pos);
	int Count();
	friend SetClose Union(SetClose l, SetClose r); //obyednannya
	friend SetClose Intersection(SetClose l, SetClose r); //peretyn
	friend SetClose Substraction(SetClose l, SetClose r); //riznycya

	SetClose& operator++();
	SetClose& operator--();
	SetClose operator++(int);
	SetClose operator--(int);



};

