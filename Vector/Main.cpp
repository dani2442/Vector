#include "Vector.h"
int main() {
	Vector<double> v4; v4.v = { {1,2},{3,4},{3,6} };
	Vector<double> v5; v5.v = { { 1,2 },{ 3,4 },{ 3,6 } };
	v4*=v5;
	v4.Print();

	getchar();
}