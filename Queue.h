template<class T>
class Queue
{
	private:
		T *Data;
		int Head, Tail;
	public:
		Queue(int Size);
		~Queue();
		bool IsEmpty();
		bool InQueue(T x);
		bool DeQueue(T* x);
};