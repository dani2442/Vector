#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Vector:public vector<T>
{
public:
	//Vector();
	//~Vector();

	using vector<T>::vector;
	
	bool Check_Size();
	template<typename T1>
	bool Check_Size(vector<T1>&);

	void Print();
	//const Vector<T> &operator+(int x)const {return *this;}
	//Vector<T> operator-(const Vector<T> &a, const Vector<T> &b);
	//Vector<T> operator+(const Vector<T> &a, const Vector<T> &b);

private:

	void Recursive_Check(vector<T>&);
	vector Sum(const Vector<T>&, const Vector<T>&);

};

template<typename T>
Vector<T> operator-(const Vector<T> &a, const Vector<T> &b)
{

	return a;
}

template<typename T>
Vector<T> operator+(const Vector<T> &a, const Vector<T> &b)
{
	return a;
}

template<typename T>
void Vector<T>::Recursive_Check(vector<T>& v1) {

}
template<typename T>
bool Vector<T>::Check_Size()
{
	if (is_fundamental<T>::value) {
		return true;
	}
	else {
		size_t size_y = 0;
		for (typename vector<T>::iterator it = (*this).begin(); it != (*this).end(); ++it) {
			if (size_y != 0) {
				if (size_y != (*it).size())
				{
					cout << "matriz invalida" << endl;
					return false;
				}
			}
			else {
				size_y = (*it).size();
			}
		}
	}
}

template<typename T>
template<typename T1>
bool Vector<T>::Check_Size(vector<T1>&mysize)
{
	if (!is_fundamental<T1>::value) {
		cout << "error parametro dimension";
		return false;
	}

	T1 size_x = 0;
	T1 size_y = 0;

	for (typename vector<vector<T>>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
		if (size_y != 0) {
			if (size_y != (*it).size())
			{
				cout << "matriz invalida" << endl;
				return false;
			}
		}
		else {
			size_y = (*it).size();
		}
		size_x++;
	}
	mysize[0] = size_x;
	mysize[1] = size_y;
	return true;
}


template<typename T>
void Vector<T>::Print()
{
	if (!Check_Size())
		return;

	if (!is_fundamental<T>::value) {
		for (typename Vector<T>::iterator it1 = (*this).begin(); it1 != (*this).end(); it1++) {
			for (typename T::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
				cout << *it2 << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else {
		for (typename vector<T>::iterator it2 = this->begin(); it2 != this->end(); it2++) {
			cout << &it2 << " ";
		}
		cout << endl;
	}
}









