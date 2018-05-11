#include "Vector.h"

int main() {
	Vector<vector<double>> v1;
	v1.v= { {3, 2}, { 4,5 }, { 3,5 } };
	Vector<vector<double>> v2; v2.v = { { 3,2 },{ 2,3 },{3,4} };
	Vector<vector<double>> v3;
	Vector<vector<double>> v4;
	Vector<int> dani; dani.v = { 3,4,5,6 };
	
	dani=dani*3;
	v1.Check_Size();
	v1.Print();
	v1.Transponse();
	v1.Print();
	getchar();
}