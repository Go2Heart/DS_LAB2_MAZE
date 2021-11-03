#include<cstdio>
#include<cstdlib>
#include "Array.h"
template<class T> Array<T>::Array(int InitN, int InitM)
{
	Data = new T[InitN * InitM];
	if(!Data)
		fprintf(stderr, "Array Initialization Failed!\n");
	N = InitN, M = InitM;
}
template<class T> Array<T>::~Array()
{
	if(Data)
	{
		delete[] Data;
		Data = NULL;
	}
}
template<class T> bool Array<T>::Assign(int x, int y, T val)
{
	if(x <= 0 || x > N || y <= 0 || y > M) return 0;
	Data[(x - 1) * M + y] = val;
	return 1;
}
template<class T> bool Array<T>::Value(int x, int y, T* val)
{
	if(x <= 0 || x > N || y <= 0 || y > M) return 0;
	(*val) = Data[(x - 1) * M + y];
	return 1;
}