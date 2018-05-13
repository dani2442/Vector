#include "Vector.h"

int main() {
	Vector<double> v4; v4.v = { {1,2},{3,4},{3,6} };
	v4.Transponse();
	v4.Print();

	
	getchar();
}