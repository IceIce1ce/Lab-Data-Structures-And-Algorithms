#include"hash_table.h"

int main()
{
	//vector<Company> ll = ReadCompanyList("MST.txt");
	//string company_name = "CONG TY TINH BEE VIET NAM";
	//cout << HashString(company_name);
	//CreateHashTable(ReadCompanyList("MST.txt"));
	//Company name = ReadCompany("CONG TY CO PHAN CHUNG KHOAN HO CHI MINH|0302910950|76 Le Lai, Phuong Ben Thanh, Quan 1, Ho Chi Minh");
	//Company* table = new Company[2000];
	//Insert(table, name);
	Company* table = CreateHashTable(ReadCompanyList("MST.txt"));
	string name_search = "CONG TY TINH BEE VIET NAM";
	Search(table, name_search);
	return 0;
}