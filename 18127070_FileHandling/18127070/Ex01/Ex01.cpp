#include"Ex01.h"
#include<algorithm>
#include<sstream>
#include<iterator>

Examinee ReadExaminee(string line_info)
{
	Examinee ex;
	ex.math = ex.literature = ex.physic = ex.chemistry = ex.biology = ex.literature = ex.geography = ex.civic_education = ex.natural_science = ex.social_science = ex.foreign_language = 0;
	vector<string> tokens = Tokenizer::Parse(line_info, ",");
	for (auto i = 2; i < tokens.size() - 2; i++) 
	{
		if (tokens[i].empty())
		{
			tokens[i] = "0";
		}
	}
	/*for (auto i = 0; i < tokens.size(); i++) 
	{
		cout << tokens[i] << " "; 
	}
	system("pause");*/ 
	ex.ID = tokens[0];
	ex.math = stof(tokens[2]);
	ex.literature = stof(tokens[3]);
	ex.physic = stof(tokens[4]);
	ex.chemistry = stof(tokens[5]);
	ex.biology = stof(tokens[6]);
	ex.history = stof(tokens[7]);
	ex.geography = stof(tokens[8]);
	ex.civic_education = stof(tokens[9]);
	ex.natural_science = ex.physic + ex.chemistry + ex.biology; 
	ex.social_science = ex.history + ex.geography + ex.civic_education;
	ex.foreign_language = stof(tokens[12]); 
	return ex; 
}

vector<Examinee> ReadExamineeList(string file_name)
{
	vector<Examinee> ll;
	ifstream fin;
	fin.open(file_name);
	if (!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	fin.ignore(EMPTY_LINE, '\n'); 
	string line; 
	Examinee ex;
	while(!fin.eof())
	{
		getline(fin, line, '\n');
		if (line.size() > 0) 
		{ 
			ex = ReadExaminee(line);
			ll.push_back(ex);
		}
	}
	fin.close();
	cout << "Read and write file successfully" << endl;
	return ll;
} 

void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name)
{
	ofstream fout;
	fout.open(out_file_name);
	if(!fout.is_open())
	{
		cerr << "File can't open";
		exit(0);
	}
	for(auto i = 0; i < examinee_list.size(); i++)
	{
		fout << examinee_list[i].ID << " " << examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].natural_science + examinee_list[i].social_science << endl;
	}
	fout.close();
}