#include"Ex01.h"

int main()
{
	vector<Examinee> list = ReadExamineeList("data.txt");
	WriteSumOfScore(list, "output.txt");
	return 0;
}