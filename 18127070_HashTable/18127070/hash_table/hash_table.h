#include<iostream>
#include<fstream>
#include<string>
#include"Tokenizer.h"
using namespace std;
#define EMPTY_LINE 1000000

struct Company
{
	string name, profit_tax, address;
};
Company ReadCompany(string line_info);
vector<Company> ReadCompanyList(string file_name);
long long HashString(string company_name);
Company* CreateHashTable(vector<Company> list_company);
void Insert(Company* hash_table, Company company);
Company* Search(Company* hash_table, string company_name);