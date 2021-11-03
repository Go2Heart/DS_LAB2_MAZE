template<class T>
class Stack
{
	private:
		T *Data;
		int Top;
	public:
		Stack(int Size);
		~Stack();
		bool IsEmpty();
		bool Push(T x);
		bool Pop(T* x);
};