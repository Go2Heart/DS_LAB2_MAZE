#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<string>
using namespace std;
int main()
{
	srand(time(NULL));
	string prefix1, prefix2, suffix1, suffix2, now;
	prefix1 = "TestData/Maze",prefix2 = "test", suffix1 = ".in",suffix2 = ".out";
	for(int TestRound = 1; TestRound <= 5; TestRound++)
	{
	//此循环用来自动将我们设计好的4个测试用例(TestData/Maze.in)载入test.in以供main.cpp读取
	//并将运行结果与TestData文件夹下内置的输出文件 调用cmd中 fc指令进行比较
	//若比较无误则会输出  Test xx Passed!  字样
		char tmp[20];
		int InitN, InitM, Tmp;
		itoa(TestRound, tmp, 10);
		now = tmp;
		FILE *fin = fopen((prefix1 + now + suffix1).c_str(), "r");
		FILE *testin = fopen((prefix2 + suffix1).c_str(), "w");
		fscanf(fin, "%d%d", &InitN, &InitM);
		fprintf(testin, "%d %d\n", InitN, InitM);
		for(int i = 1; i <= InitN; i++)
			for(int j = 1; j <= InitM; j++)
			{
				fscanf(fin, "%d", &Tmp);
				fprintf(testin, "%d%c", Tmp, j == InitM ? '\n' : ' ');
			}
		for(int i = 1; i <= 2; i++)
			for(int j = 1; j <= 2; j++)
			{
				fscanf(fin, "%d", &Tmp);
				fprintf(testin, "%d%c", Tmp, j == 2 ? '\n' : ' ');
			}
		fclose(fin);
		fclose(testin);
		system("Test");
		string prefix3 = "fc SolByDfs.out TestData/SolByDfs";
		string prefix4 = "fc SolByBfs.out TestData/SolByBfs";
		string prefix5 = "fc AllPath.out TestData/AllPath";
		if(system((prefix3 + now + suffix2).c_str()) || system((prefix4 + now + suffix2).c_str()) || system((prefix5 + now + suffix2).c_str()))
		{
			fprintf(stderr, "ERROR! at %d Test!", TestRound);
			return 0;
		} else 
		{
			fprintf(stderr, "Test %d Passed!\n", TestRound);
		}
	}
	fprintf(stderr, "Fixed TestData(Test 1~5) Passed!\n");
	Sleep(1000); 
}
