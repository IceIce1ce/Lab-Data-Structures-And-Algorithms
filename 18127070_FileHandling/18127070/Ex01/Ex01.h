#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Tokenizer.h"
#include<stdlib.h>
using namespace std;
#define EMPTY_LINE 1000000

struct Examinee
{
	string ID;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};
Examinee ReadExaminee(string line_info);
vector<Examinee> ReadExamineeList(string file_name);
void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name);