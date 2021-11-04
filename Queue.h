template<class T>
class Queue
{
	private:
		T *Data;
		int Head, Tail;
	public:
		Queue(){Data = NULL;}
		Queue(int Size)
		{
			Data = new T[Size];
			if(!Data)
				fprintf(stderr, "Array Initialization Failed!\n");
			Head = 0, Tail = -1;
		}
		~Queue()
		{
			if(Data)
			{
				delete[] Data;
				Data = NULL;
			}
			Head = 0, Tail = -1;
		}
		bool IsEmpty()
		{
			if(Head == Tail + 1) return 1;
			return 0;
		}
		bool InQueue(T x)
		{
			++Tail;
			Data[Tail] = x;
			return 1;
		}
		bool DeQueue(T* x)
		{
			if(Head == Tail + 1) return 0;
			(*x) = Data[Head];
			++Head;
			return 1;
		}
};