template<class T>
class Stack
{
	private:
		T *Data;
		int Top;
	public:
		Stack(){Data = NULL;}
		Stack(int Size)
		{
			Data = new T[Size];
			if(!Data)
				fprintf(stderr, "Array Initialization Failed!\n");
			Top = -1;
		}
		~Stack()
		{
			if(Data)
			{
				delete[] Data;
				Data = NULL;
			}
			Top = -1;
		}
		bool IsEmpty()
		{
			if(Top == -1) return 1;
			return 0;
		}
		bool Push(T x)
		{
			++Top;
			Data[Top] = x;
			return 1;
		}
		bool Pop(T* x)
		{
			if(Top == -1) return 0;
			(*x) = Data[Top];
			--Top;
			return 1;
		}
};
