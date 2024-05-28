#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <class T>
class vector
{
	T* v;
	int size;
public:
	vector(int newsize);
	vector(vector&);
	~vector();

	friend vector<T> operator + <>(vector<T>& x, vector<T>& y);
	vector<T>& operator *= (T number);
	T& operator [] (int index);
	vector& operator = (const vector&);
	friend istream& operator >> <>(istream&, vector&);
	friend ostream& operator << <>(ostream&, vector&);
};

template <class T>
vector<T>::vector(int newsize)
{
	v = new T[size = newsize];
	for (int i = 0; i < size; i++)
		v[i] = T();
}

template <class T>
vector<T>::vector(vector<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}

template <class T>
vector<T>::~vector()
{
	delete[] v;
}

template <class T>
vector<T> operator + (vector<T>& x, vector<T>& y)
{
	if (x.size != y.size)
	{
		throw exception("The sizes should be the same!");
	}
	vector<T> z(x.size);
	for (int i = 0; i < x.size; i++)
		z.v[i] = x.v[i] + y.v[i];
	return z;
}

template <class T>
vector<T>& vector<T>::operator *= (T number)
{
	for (int i = 0; i < size; i++)
		v[i] *= number;
	return *this;
}

template <class T>
T& vector<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
		return v[index];
}

template <class T>
vector<T>& vector<T>::operator = (const vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ";
		is >> x.v[i];
	}
	return is;
}

template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}

int main()
{
	try
	{
		vector<int> V(5), U(5), Z(5), T(5);
		cin >> V;
		cin >> U;
		T = V + U;
		cout << "summa of vectors:" << endl;
		cout << T;
		int number = 7;
		V *= number;
		cout << "multiplying vector" << endl;
		cout << V;
	}
		catch (exception e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
};
