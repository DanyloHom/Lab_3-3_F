#include "SetOpen.h"
#include <iostream>

using namespace std;

SetOpen::SetOpen()
{
	setFirst(0);
	setSecond(0);
}

SetOpen::SetOpen(const SetOpen& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());
}

SetOpen::SetOpen(unsigned long l, unsigned long r)
{
	setFirst(l);
	setSecond(r);
}


SetOpen& SetOpen::operator=(const SetOpen& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());

	return *this;
}

SetOpen& SetOpen::operator=(const BitString& b)
{
	setFirst(b.getFirst());
	setSecond(b.getSecond());

	return *this;

}


void SetOpen::Exclude(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() & ~(~(~0 << 1) << pos));
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() & ~(~(~0 << 1) << pos));
	else cout << "wrong argument" << endl;
}

void SetOpen::Include(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() | ~(~0 << 1) << pos);
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() | ~(~0 << 1) << pos);
	else cout << "wrong argument" << endl;
}

int SetOpen::Count()
{
	int count = 0;
	unsigned long l = getFirst();
	unsigned long r = getSecond();

	while (l) {             //poky l ne stane 0
		count += l & 1;		//dodayemo do count kzhnu odynychku
		l >>= 1;			//rozglyadaemo nastypnyi bit
	}

	while (r) {				//poky r ne stane 0
		count += r & 1;		//dodayemo do count kzhnu odynychku
		r >>= 1;			//rozglyadaemo nastypnyi bit
	}

	return count;
}



SetOpen Union(SetOpen l, SetOpen r)
{
	SetOpen A;
	A = Or(l, r);

	return A;
}


SetOpen Intersection(SetOpen l, SetOpen r)
{
	SetOpen A;
	A = And(l, r);

	return A;
}

SetOpen Substraction(SetOpen l, SetOpen r)
{
	SetOpen A;
	A = XOr(l, r);

	return A;

}