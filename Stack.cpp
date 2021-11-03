#include<cstdio>
#include<cstdlib>
#include "Stack.h"
template<class T> Stack<T>::Stack(int Size)
{
	Data = new T[Size];
	if(!Data)
		fprintf(stderr, "Array Initialization Failed!\n");
	Top = -1;
}
template<class T> Stack<T>::~Stack()
{
	if(Data)
	{
		delete[] Data;
		Data = NULL;
	}
	Top = -1;
}
template<class T> bool Stack<T>::IsEmpty()
{
	if(Top == -1) return 1;
	return 0;
}
template<class T> bool Stack<T>::Push(T x)
{
	++Top;
	Data[Top] = x;
	return 1;
}
template<class T> bool Stack<T>::Pop(T* x)
{
	if(!Top) return 0;
	(*x) = Data[Top];
	--Top;
	return 1;
}