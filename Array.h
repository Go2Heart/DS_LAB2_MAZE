template<class T>
class Array
{
	private:
		T *Data;
		int N, M;
	public:
		Array(){Data = NULL;}
		Array(int InitN, int InitM, T val)
		{
			Data = new T[InitN * InitM];
			if(!Data)
				fprintf(stderr, "Array Initialization Failed!\n");
			for(int i = 0; i < InitN * InitM; i++) Data[i] = val;
			N = InitN, M = InitM;
		}
		~Array()
		{
			if(Data)
			{
				delete[] Data;
				Data = NULL;
			}
		}
		bool Assign(int x, int y, T val)
		{
			if(x <= 0 || x > N || y <= 0 || y > M) return 0;
			Data[(y - 1) * N + x - 1] = val;
			return 1;
		}
		bool Value(int x, int y, T* val)
		{
			if(x <= 0 || x > N || y <= 0 || y > M) return 0;
			(*val) = Data[(y - 1) * N + x - 1];
			return 1;
		}
};
