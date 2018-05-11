#pragma once
#include <vector>
#include <iostream>
using namespace std;


template <typename T>
const bool Check_Size_2D(vector<vector<T>> myvector) {
	size_t size_y = 0;
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
	}
	return true;
}

template <typename T, typename T1>
const bool Check_Size_2D(vector<vector<T>> myvector, vector<T1> &mysize) {
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
const vector<vector<T>> Transponse_2D(vector<vector<T>> myvector) {
	vector<int> mysize(2);
	if (!Check_Size_2D(myvector, mysize)) {
		return {};
	}
	vector<vector<T>> myvector2(mysize[1],vector<T>(mysize[0]));
	int i = 0;
	for (typename vector<vector<T>>::iterator it1 = myvector.begin(); it1 != myvector.end(); ++it1,i++) {
		int j = 0;
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2,j++) {
			myvector2[j][i] = *it2;
		}
	}
	return myvector2;
}

template<typename T>
const void Print_2D(vector<vector<T>> myvector) {
	if (!Check_Size_2D(myvector))
		return;
	for (typename vector<vector<T>>::iterator it1 = myvector.begin(); it1 != myvector.end(); it1++) {
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T,typename S>
const void Scalar_Product_2D(vector<vector<T>> &myvector, S scalar) {
	for (typename vector<vector<T>>::iterator it1 = myvector.begin(); it1 != myvector.end(); it1++) {
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			it2 *= scalar;
		}
		cout << endl;
	}
}

template<typename T>
const vector<vector<T>> Vectorial_Product(vector<vector<T>> vector1, vector<vector<T>> vector2) {
	vector<int> s1(2), s2(2);
	Check_Size_2D(vector1, s1);
	Check_Size_2D(vector2, s2);
	if (s1[1] != s2[0]) {
		return {};
	}
	vector<vector<T>> Result(s1[0], vector<T>(s2[1]));
	int i = 0;
	for (typename vector<vector<T>>::iterator it1 = Result.begin(); it1 != Result.end(); it1++, i++) {
		int j = 0;
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++, j++) {
			for (int k = 0; k < s1[1]; k++) {
				*it2 += vector1[i][k] * vector2[k][j];
			}
		}
	}
	return Result;
}

template<typename T>
const vector<vector<T>> Sum_2D(vector<vector<T>> vector1, vector<vector<T>> vector2) {
	vector<int> s1(2),s2(2);
	Check_Size_2D(vector1, s1);
	Check_Size_2D(vector2, s2);
	vector<vector<T>>result(s1[0], vector<T>(s1[1]));
	if (!((s1[0] == s2[0]) && (s1[1] == s2[1]))) {
		cout << "no se puede operar";
	}
	int i = 0;
	for (typename vector<vector<T>>::iterator it1 = result.begin(); it1 != result.end(); it1++,i++) {
		int j = 0;
		for (typename vector<T>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++,j++) {
			*it2 = vector1[i][j] + vector2[i][j];
		}
		cout << endl;
	}
	return result;
}