#include<cstdio>
#include<cstdlib>
#include "Queue.h"
template<class T> Queue<T>::Queue(int Size)
{
	Data = new[Size];
	if(!Data)
		fprintf(stderr, "Array Initialization Failed!\n");
	Head = 0, Tail = -1;
}
template<class T> Queue<T>::~Queue()
{
	if(Data)
	{
		delete[] Data;
		Data = NULL;
	}
	Head = 0, Tail = -1;
}
template<class T> bool Queue<T>::IsEmpty()
{
	if(Head == Tail + 1) return 1;
	return 0;
}
template<class T> bool Queue<T>::InQueue(T x)
{
	++Tail;
	Data[Tail] = x;
	return 1;
}
template<class T> bool Queue<T>::DeQueue(T* x)
{
	if(Head == Tail + 1) return 0;
	(*x) = Data[Head];
	++Head;
	return 1;
}