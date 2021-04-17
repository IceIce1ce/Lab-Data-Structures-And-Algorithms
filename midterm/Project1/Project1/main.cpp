#include"function.h"

/*int main()
{
	List_Examinee *list = new List_Examinee;
	delete list;
	return 0;
}*/

int main()
{
	//vector<Examinee> ll = ReadExamineeList("data.txt"); 
	//vector<Examinee> sortedll = ReadExamineeList("descending_Literature.txt");
	//string id = FindExamineeByLiterature(sortedll, 9.0); 
	//cout << id;
	//vector<Examinee> topK = ReadExamineeList("data.txt");
	//GetTopHighestLiterature(topK, 200);
	vector<Examinee> mergeList1 = ReadExamineeList("descending_Literature_1.txt");
	vector<Examinee> mergeList2 = ReadExamineeList("descending_Literature_2.txt");
	vector<Examinee> merge = MergeTwoList(mergeList1, mergeList2);
	return 0;
}