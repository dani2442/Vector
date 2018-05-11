#include "Vector.h"

int main() {
	Vector<vector<double>> v1 = { {3,2},{4,5} };
	Vector<vector<double>> v2 = { { 3,2 },{ 2,3 } };
	Vector<vector<double>> v3;
	Vector<vector<double>> v4;
	Vector<int> dani = { 2,34,54,5 };

	v3=v1+v2;
	v4 = v1 - v2;
	v1.Check_Size();
	v1.Print();
	getchar();
}