#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include"Tokenizer.h"
#include<stdlib.h>
using namespace std;
#define EMPTY_LINE 1000000

/*class Examinee
{
private:
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
public:
	static Examinee ReadExaminee(string line_info);
	//string FindExamineeByLiterature(vector<Examinee> sorted_list, float v);
	//vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k);
	//vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2);
public:
	Examinee();
	~Examinee();
	Examinee(string ID, float mat, float lit, float phy, float chem, float bio, float his, float geo, float civic, float foreign);
	//void output();
	//vector<Examinee> ReadExamineeList(string file_name);
}; 

class List_Examinee
{
public:
	vector<Examinee> list;
	List_Examinee();
};*/

struct Examinee
{
	string ID;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};

int binarySearch(int arr[], int l, int r, int x);
Examinee ReadExaminee(string line_info);
vector<Examinee> ReadExamineeList(string file_name);
string FindExamineeByLiterature(vector<Examinee> sorted_list, float v);
vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k);
vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2);
int partition(vector<Examinee>& a, int left, int right);
void quickSort(vector<Examinee> &a, int left, int right);