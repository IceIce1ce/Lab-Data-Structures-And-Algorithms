#include"hash_table.h"
#include<algorithm>

Company ReadCompany(string line_info)
{
	Company co;
	vector<string> tokens = Tokenizer::Parse(line_info, "|");
	for (auto i = 0; i < tokens.size(); i++) 
	{
		cout << tokens[i] << " "; 
	}
	//system("pause"); 
	co.name = tokens[0];
	co.profit_tax = tokens[1];
	co.address = tokens[2];
	return co; 
}

vector<Company> ReadCompanyList(string file_name)
{
	vector<Company> ll;
	ifstream fin;
	fin.open(file_name);
	if (!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	fin.ignore(EMPTY_LINE, '\n'); 
	string line; 
	Company co;
	while(!fin.eof())
	{
		getline(fin, line, '\n');
		if (line.size() > 0) 
		{ 
			co = ReadCompany(line);
			ll.push_back(co);
		}
	}
	fin.close();
	return ll;
} 

long long HashString(string company_name)
{
	const int p = 31; //p = 51 for upper string
	const int m = 1e9 + 9;
	long long hash_value = 0;
	long long Pow = 1;
	unsigned char s = (int)(company_name.length() < 20? company_name.length(): 20);
	for(int i = 0; i < s; i++)
	//for(char c: company_name) //take each character of string company_name
	{
		s = tolower(company_name[i]);
		hash_value = (hash_value + (s - 'a' + 1) * Pow) % m;
        Pow = (Pow * p) % m;
		if(hash_value < 0) hash_value += m; //avoid negative result
	}
	return hash_value;
}

Company* CreateHashTable(vector<Company> list_company)
{
	Company *tableSize = new Company[2000];
	int index;
	for(int i = 0; i < list_company.size(); i++)
	{
		index = HashString(list_company[i].name) % 2000;
		int check = index; 
		while(tableSize[check].name.size() != 0)
		{
			check++;
			if(check == 2000) check = 0;
			if(check == index)
			{
				cout << "Full table";
				return tableSize;
			}
		}
		tableSize[check] = list_company[i];
		//cout << tableSize[index].name << endl;
	}
	return tableSize;
}

void Insert(Company* hash_table, Company company)
{
	int index;
	hash_table = CreateHashTable(ReadCompanyList("MST.txt"));
	for(int i  = 0; i < company.name.size(); i++)
	{
		index = hash_table->name.size();
		while(hash_table[index].name != "") index = (index + 1) % 2000;
		hash_table[index].name = company.name;
	}
}

Company* Search(Company* hash_table, string company_name)
{
	int index = HashString(company_name) % 2000;
	//hash_table = CreateHashTable(ReadCompanyList("MST.txt"));
	//while(hash_table[index].name != company_name && hash_table[index].name != "") index = (index + 1) % 2000;
	//if(hash_table[index].name == company_name) return hash_table;
	if(hash_table[index].name != "" && hash_table[index].name != company_name) return &hash_table[index];
	return nullptr;
}