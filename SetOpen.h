#pragma once
#include "BitString.h"

class SetOpen:
	public BitString 
{
public:
	SetOpen();
	SetOpen(const SetOpen& s);
	SetOpen(unsigned long l, unsigned long r);

	SetOpen& operator=(const SetOpen& s);
	SetOpen& operator=(const BitString& b);


	void Exclude(int pos);
	void Include(int pos);
	int Count();
	friend SetOpen Union(SetOpen l, SetOpen r); //obyednannya
	friend SetOpen Intersection(SetOpen l, SetOpen r); //peretyn
	friend SetOpen Substraction(SetOpen l, SetOpen r); //riznycya
};