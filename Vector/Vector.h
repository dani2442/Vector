#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	Vector();
	Vector(int);
	Vector(int, int);

	~Vector();

	vector<vector<T>> v;
	
	bool Check_Size() ;
	template<typename T1> bool Check_Size(vector<T1>&) ;
	template<typename T1> bool Check_Size_Fast(vector<T1>&);

	void Print();

	void Transponse();

	void Inverse();



	template<class T,class Q>
	friend vector<vector<T>> operator* (const Q , Vector<T> );
	template<class T,class Q>
	friend vector<vector<T>> operator* (Vector<T> , const Q );
	template<class T>
	friend vector<vector<T>> operator*(Vector<T>& , Vector<T>&);
	template<typename T>
	friend vector<vector<T>> operator+(Vector<T> &, Vector<T> &);
	template<typename T>
	friend vector<vector<T>> operator-(Vector<T> &, Vector<T> &);

	

	Vector<T>& operator = (const vector<vector<T>>& v)
	{
		this->v = v;
		return *this;
	}

	vector<vector<T>>& operator +=( Vector<T>&v) {
		return v + (*this);
	}

	vector<vector<T>>& operator -=(Vector<T>&v) {
		return v - (*this);
	}

	vector<vector<T>>& operator *=(Vector<T>&v) {
		return v * (*this);
	}
	

private:

	void Recursive_Check(vector<T>&);

};



template <typename T>
Vector<T>::Vector(){
}

template<class T>
inline Vector<T>::Vector(int size):
	v(size,vector<T>(size))
{
}

template<class T>
inline Vector<T>::Vector(int size_x, int size_y):
	v(size_x,vector<T>(size_y))
{
}

template <typename T>
Vector<T>::~Vector() {
}


template <class T, class Q>
vector<vector<T>> operator* (const Q c, Vector<T> v1)
{
	for (vector<vector<T>>::iterator it = v1.v.begin(); it != v1.v.end(); it++) {
		for (vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
			*it2 *= c;
		}
	}
	return v1.v;
}

template <class T, class Q>
vector<vector<T>> operator* ( Vector<T> v1,const Q c)
{
	for (vector<vector<T>>::iterator it = v1.v.begin(); it != v1.v.end(); it++) {
		for (vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
			*it2 *= c;
		}
	}
	return v1.v;
}

template<class T>
vector<vector<T>> operator*( Vector<T>& vector1, Vector<T>&vector2) {
	vector<int>N1(2), N2(2);
	vector1.Check_Size_Fast(N1);
	vector2.Check_Size_Fast(N2);

	if(N1[1]!=N2[0])
		return {};

	vector<vector<T>> Result(N1[0], vector<T>(N2[1]));
	int i = 0;
	for (typename vector<vector<T>>::iterator it1 = Result.begin(); it1 != Result.end(); it1++, i++) {
		int j = 0;
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++, j++) {
			for (int k = 0; k < N1[1]; k++) {
				*it2 += vector1.v[i][k] * vector2.v[k][j];
			}
		}
	}
	return Result;
}

template<typename T>
vector<vector<T>> operator+(Vector<T> &a, Vector<T> &b)
{
	vector<int>N1(2), N2(2);
	if (!(a.Check_Size_Fast(N1) && b.Check_Size_Fast(N2)))
		return {};

	if ((N1[0] != N2[0]) || (N1[1] != N2[1]))
		return {};
	vector<vector<T>>Result(N1[0], vector<T>(N1[1]));
	for (int i = 0; i < N1[0]; i++) {
		for (int j = 0; j < N1[1]; j++) {
			Result[i][j] = a.v[i][j] + b.v[i][j];
		}
	}
	return Result;

}


template<typename T>
vector<vector<T>> operator-(Vector<T> &a, Vector<T> &b)
{
	vector<int>N1(2), N2(2);
	if (!(a.Check_Size_Fast(N1) && b.Check_Size_Fast(N2)))
		return {};

	if ((N1[0] != N2[0]) || (N1[1] != N2[1]))
		return {};
	vector<vector<T>>Result(N1[0], vector<T>(N1[1]));
	for (int i = 0; i < N1[0]; i++) {
		for (int j = 0; j < N1[1]; j++) {
			Result[i][j] = a.v[i][j] - b.v[i][j];
		}
	}
	return Result;
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
		for (typename vector<vector<T>>::iterator it = this->v.begin(); it != this->v.end(); ++it) {
			if (size_y != 0) {
				if (size_y != it->size())
				{
					cout << "matriz invalida" << endl;
					return false;
				}
			}
			else {
				size_y = it->size();
			}
		}
	}
}
template<typename T>
template<typename T1>
bool Vector<T>::Check_Size_Fast(vector<T1>&mysize)
{
	mysize[0] = this->v.size();
	mysize[1] =this->v[0].size();
	return true;
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

	for (int i = 0; i < this->v.size(); i++) {
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

	for (typename vector<vector<T>>::iterator it1 = this->v.begin(); it1 != this->v.end(); it1++) {
		for (typename vector<T>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
	cout << endl;

}

template<typename T>
inline void Vector<T>::Transponse()
{
	vector<int> mysize(2);
	if (!this->Check_Size_Fast(mysize)) {
		return;
	}
	vector<vector<T>> myvector2(mysize[1], vector<T>(mysize[0]));
	int i = 0;
	for (typename vector<vector<T>>::iterator it1 = this->v.begin(); it1 != this->v.end(); ++it1, i++) {
		int j = 0;
		for (typename vector<T>::iterator it2 = it1->begin(); it2 != it1->end(); ++it2, j++) {
			myvector2[j][i] = *it2;
		}
	}
	this->v = myvector2;
	return;
}

template<typename T>
inline void Vector<T>::Inverse()
{
	if (this->v.size() != this->v[0].size())
	{
		cout << "ERROR on inverse() not square array" << endl; getchar(); return;//returns a null
	}

	size_t dim = this->v.size();
	int i, j, ord;
	vector< vector<T> > x(dim, vector<T>(dim)), y(dim, vector<T>(dim));//output
	x = this->v;																			  //init_2Dvector(x, dim, dim); x = x2;																			  //init_2Dvector(y, dim, dim);
																					  //1. Unity array y: 
	for (i = 0; i<dim; i++)
		for (j = 0; j<dim; j++)
		{
			if (i == j)
				y[i][j] = 1.0;
			else
				y[i][j] = 0.0;
		}

	double diagon, coef;
	double *ptrx, *ptry, *ptrx2, *ptry2;
	for (ord = 0; ord<dim; ord++)
	{
		//2 Hacemos diagonal de x =1
		diagon = x[ord][ord];
		if (fabs(diagon)<1e-15)
		{
			long i2;
			for (i2 = ord + 1; i2<dim; i2++)
			{
				if (fabs(x[ord][i2])>1e-15) break;
			}
			if (i2 >= dim)
				return;//error, returns null
			for (i = 0; i<dim; i++)//sumo la linea que no es 0 el de la misma fila de ord
			{
				x[ord + i][ord] += x[ord + i][i2];
			}
		}
		ptry = &y[ord][0];
		for (i = 0; i<dim; i++)
			*ptry++ /= diagon;
		ptrx = &x[ord][ord];
		for (i = ord; i<dim; i++)//para i<ord *ptrx=0,
			*ptrx++ /= diagon;

		//Hacemos '0' la columna ord salvo elemento diagonal:
		for (i = 0; i<dim; i++)//Empezamos por primera fila
		{
			if (i == ord) continue;
			coef = x[i][ord];//elemento ha hacer 0 
			if (fabs(coef)<1e-15) continue; //si es cero se evita
			ptry = &y[i][0];
			ptry2 = &y[ord][0];
			for (j = 0; j<dim; j++)
				*ptry++ = *ptry - coef * (*ptry2++);
			ptrx = &x[i][ord];
			ptrx2 = &x[ord][ord];
			for (j = ord; j<dim; j++)
				*ptrx++ = *ptrx - coef * (*ptrx2++);
		}
	}//end ord
	this->v = y;
}