#include "SetClose.h"
#include <iostream>

using namespace std;

SetClose::SetClose()
{
	setFirst(0);
	setSecond(0);
}

SetClose::SetClose(const SetClose& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());
}


SetClose& SetClose::operator=(const SetClose& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());

	return *this;
}

SetClose& SetClose::operator=(const BitString& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());

	return *this;
}


void SetClose::Exclude(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() & ~(~(~0 << 1) << pos));
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() & ~(~(~0 << 1) << pos));
	else cout << "wrong argument" << endl;
}

void SetClose::Include(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() | ~(~0 << 1) << pos);
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() | ~(~0 << 1) << pos);
	else cout << "wrong argument" << endl;
}

int SetClose::Count()
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

SetClose& SetClose::operator++()
{
	int i = getFirst();
	setFirst(i++);
	i = getSecond();
	setSecond(i++);
	return *this;
}

SetClose& SetClose::operator--()
{
	int i = getFirst();
	setFirst(i--);
	i = getSecond();
	setSecond(i--);
	return *this;
}

SetClose SetClose::operator++(int)
{
	SetClose tmp(*this);
	int i = getFirst();
	setFirst(i++);
	i = getSecond();
	setSecond(i++);
	return *this;

	return tmp;
}

SetClose SetClose::operator--(int)
{
	SetClose tmp(*this);
	int i = getFirst();
	setFirst(i--);
	i = getSecond();
	setSecond(i--);
	return *this;

	return tmp;
}


ostream& operator<<(ostream& out, SetClose& s)
{
	out << string(s);
	return out;
}

istream& operator>>(istream& in, SetClose& s)
{
	unsigned long i;
	cout << "enter first " << endl;
	in >> i;
	s.setFirst(i);
	cout << "enter second " << endl;
	in >> i;
	s.setSecond(i);

	return in;
}

SetClose Union(SetClose l, SetClose r)
{
	SetClose A;
	A = Or(l, r);

	return A;
}

SetClose Intersection(SetClose l, SetClose r)
{
	SetClose A;
	A = And(l, r);

	return A;
}

SetClose Substraction(SetClose l, SetClose r)
{
	SetClose A;
	A = XOr(l, r);

	return A;

}