#include "Vector.h"

int main() {
	Vector<double> v1;
	v1.v= { {3, 2}, { 4,5 }, { 3,5 } };
	Vector<double> v2; v2.v = { { 3,2 },{ 2,3 },{3,4} };
	Vector<double> v3(2);
	Vector<double> v4; v4.v = { {1,2},{3,4} };
	v1.Print();
	v1+= v2;
	3*v1;
	v1*v1;
	v1.Check_Size();
	v1.Print();
	v1.Transponse();
	v1.Print();
	v4.Inverse();
	v4.Print();
	getchar();
}