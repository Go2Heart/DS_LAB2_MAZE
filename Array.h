template<class T>
class Array
{
	private:
		T *Data;
		int N, M;
	public:
		Array(int InitN, int InitM);
		~Array();
		bool Assign(int x, int y, T val);
		bool Value(int x, int y, T* val);
};