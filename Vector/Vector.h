#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Vector
{
public:
	//Vector() :v();
	//~Vector();
	vector<T> v;
	//using vector<T>::vector;
	
	bool Check_Size() ;
	template<typename T1> bool Check_Size(vector<T1>&) ;

	void Print();

	void Transponse();

	Vector<T>& operator = (const vector<T>& v)
	{
		this->v = v;
		return *this;
	}
	//const Vector<T> &operator+(int x)const {return *this;}
	//Vector<T> operator-(const Vector<T> &a, const Vector<T> &b);
	//Vector<T> operator+(const Vector<T> &a, const Vector<T> &b);

private:

	void Recursive_Check(vector<T>&);

};



template<typename T>
Vector<T> operator-(const Vector<T> &a, const Vector<T> &b)
{
	vector<int>N1(2), N2(2);
	if (!(a.Check_Size(N1) && b.Check_Size(N2)))
		return {};

	if (is_fundamental<T>::value) {
		if (a.v.size() != b.v.size()) {}
			return {};

	}
	else {
		if ((N1[0] != N2[0]) || (N1[1] != N2[1]))
			return {};
		vector<T>Result(N1[0], T(N1[1]));
		for (int i = 0; i < N1[0]; i++) {
			for (int j = 0; j < N1[1]; j++) {
				Result[i][j] = a.v[i][j] - b.v[i][j];
			}
		}
		return Result;
	}
}

template<typename T>
vector<T> operator+( Vector<T> &a,  Vector<T> &b)
{
	vector<int>N1(2), N2(2);
	if (!(a.Check_Size(N1) && b.Check_Size(N2)))
		return {};
	
	if (is_fundamental<T>::value) {
		if (a.v.size() != b.v.size()){}
		return {};		

	}
	else {
		if ((N1[0] != N2[0]) || (N1[1] != N2[1])) 
			return {};
		vector<T>Result(N1[0], T(N1[1]));
		for (int i = 0; i < N1[0]; i++) {
			for (int j = 0; j < N1[1]; j++) {
				Result[i][j] = a.v[i][j] + b.v[i][j];
			}
		}
		return Result;
	}
	
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
		for (typename vector<T>::iterator it =this->v.begin(); it != this->v.end(); ++it) {
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

	for (int i = 0; i < this->v.size();i++) {
		if (size_y != 0) {
			if (size_y != this->v[i].size())
			{
				cout << "matriz invalida" << endl;
				return false;
			}
		}
		else {
			size_y = this->v[i].size();
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
	if (!this->Check_Size())
		return;

	if (!is_fundamental<T>::value) {
		for (typename vector<T>::iterator it1 = this->v.begin(); it1 != this->v.end(); it1++) {
			for (typename T::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
				cout << *it2 << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else {
		for (typename vector<T>::iterator it2 = this->v.begin(); it2 != this->v.end(); it2++) {
			cout << &it2 << " ";
		}
		cout << endl;
	}
}

template<typename T>
inline void Vector<T>::Transponse()
{
	vector<int> mysize(2);
	if (!this->Check_Size(mysize)) {
		return ;
	}
	vector<T> myvector2(mysize[1], T(mysize[0]));
	int i = 0;
	for (typename vector<T>::iterator it1 = this->v.begin(); it1 != this->v.end(); ++it1, i++) {
		int j = 0;
		for (typename T::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2, j++) {
			myvector2[j][i] = *it2;
		}
	}
	this->v = myvector2;
	return;
}









