#pragma once
#include <vector>
using namespace std;

template<typename T>
class Vector:public vector<T>
{
public:
	//Vector();
	//~Vector();

	using vector<T>::vector;
	
	const Vector<T> &operator+(int x)const {
		return *this;
	}

private:
	//vector Sum(const Vector<T>&, const Vector<T>&);

};

template<typename T>
inline Vector Vector<T>::operator-(Vector<T> a, Vector<T> b)
{
	return Vector();
}
