#include <iostream>
#include "SetOpen.h"
#include "SetClose.h"
using namespace std;

int main()
{
	cout << "SetOpen demonstration : " << endl<< endl;

	SetOpen A, B, C;
	cout << "Set a : " << endl;
	cin >> A;
	cout << A;
	cout << "Set b : " << endl;
	cin >> B;
	cout << B;

	cout << "Set c = Union(a, b) : " << endl;
	C = Union(A, B);
	cout << C;

	cout << "Set c = Intersection(a, b) : " << endl;
	C = Intersection(A, B);
	cout << C;

	cout << "Set c = Substraction(a, b) : " << endl;
	C = Substraction(A, B);
	cout << C;

	cout << "b++" << endl;
	B++;
	cout << B << endl;

	cout << "b--" << endl;
	B--;
	cout << B << endl;

	cout << "++b" << endl;
	++B;
	cout << B << endl;

	cout << "--b" << endl;
	--B;
	cout << B << endl;

	cout << "there is " << B.Count() << " elements in b" << endl;
	cout << "there is " << C.Count() << " elements in c" << endl;
	cout << "there is " << A.Count() << " elements in a" << endl;

	int i;
	cout << "enter position in a to include : " << endl;
	cin >> i;
	A.Include(i);
	cout << A;

	cout << "enter position in a to exclude : " << endl;
	cin >> i;
	A.Exclude(i);
	cout << A;

	cout << "SetClose demonstration : " << endl << endl;

	SetClose a, b, c;
	cout << "Set a : " << endl;
	cin >> a;
	cout << a;
	cout << "Set b : " << endl;
	cin >> b;
	cout << b;

	cout << "Set c = Union(a, b) : " << endl;
	c = Union(a, b);
	cout << c;

	cout << "Set c = Intersection(a, b) : " << endl;
	c = Intersection(a, b);
	cout << c;

	cout << "Set c = Substraction(a, b) : " << endl;
	c = Substraction(a, b);
	cout << c;

	cout << "b++" << endl;
	b++;
	cout << b << endl;

	cout << "b--" << endl;
	b--;
	cout << b << endl;

	cout << "++b" << endl;
	++b;
	cout << b << endl;

	cout << "--b" << endl;
	--b;
	cout << b << endl;

	cout << "there is " << b.Count() << " elements in b" << endl;
	cout << "there is " << c.Count() << " elements in c" << endl;
	cout << "there is " << a.Count() << " elements in a" << endl;

	cout << "enter position in a to include : " << endl;
	cin >> i;
	a.Include(i);
	cout << a;

	cout << "enter position in a to exclude : " << endl;
	cin >> i;
	a.Exclude(i);
	cout << a;

}