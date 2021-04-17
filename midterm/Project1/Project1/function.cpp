#include"function.h"
#include<algorithm>
#include<sstream>
#include<iterator>

/*Examinee::Examinee()
{
	this->id = "";
	this->math = this->literature = this->physic = this->chemistry = this->biology = this->history = this->geography = this->civic_education = this->natural_science = this->social_science = this->foreign_language = 0;
}

Examinee::~Examinee()
{
}

Examinee::Examinee(string ID, float mat, float lit, float phy, float chem, float bio, float his, float geo, float civic, float foreign)
{
	this->id = ID;
	this->math = mat;
	this->literature = lit;
	this->physic = phy;
	this->chemistry = chem;
	this->biology = bio;
	this->history = his;
	this->geography = geo;
	this->civic_education = civic;
	this->natural_science = math + chemistry + biology;
	this->social_science = history + geography + civic_education;
	this->foreign_language = foreign;
}

Examinee Examinee::ReadExaminee(string line_info)
{
	string id;
	float mat, lit, phy, che, bio, his, geo, civic, fore;
	vector<string> token = Tokenizer::Parse(line_info, ",");
	for(auto i = 2; i < token.size() - 2; i++)
	{
		if(token[i].empty())
		{
			token[i] = "0";
		}
	}
	for(auto i = 0; i < token.size(); i++)
	{
		cout << token[i] << " ";
	}
	//system("pause");
	unsigned char pos = 2;
	id = token[0];
	mat = stof(token[pos]);
	lit = stof(token[pos + 1]);
	phy = stof(token[pos + 2]);
	che = stof(token[pos + 3]);
	bio = stof(token[pos + 4]);
	his = stof(token[pos + 5]);
	geo = stof(token[pos + 6]);
	civic = stof(token[pos + 7]);
	fore = stof(token[pos + 8]);
	Examinee exam(id, mat, lit, phy, che, bio, his, geo, civic,fore);
	return exam;
}

List_Examinee::List_Examinee()
{
	ifstream fin;
	fin.open("data.txt");
	if(!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	fin.ignore(EMPTY_LINE, '\n');
	while(!fin.eof())
	{
		string str;
		getline(fin, str, '\n');
		if(str.size() > 0)
		{
			Examinee exam = Examinee::ReadExaminee(str);
		}
	}
	fin.close();
}

void Examinee::output()
{
	cout << "Point find by literature: " << literature << endl;
}

string Examinee::FindExamineeByLiterature(vector<Examinee> sorted_list, float v)
{
	string str = "Not found";
	cout << "Enter literature point you want to search: ";
	cin >> v;
	ifstream fin;
	fin.open("descending_Literature.txt");
	if(!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	for(int i = 0; i < sorted_list.size(); i++)
	{
		if(sorted_list[i].literature == v) sorted_list[i].output();
	}
	fin.close();
	return str;
}

vector<Examinee> Examinee::GetTopHighestLiterature(vector<Examinee> list_examinee, int k)
{
    vector<Examinee> data = list_examinee;
    nth_element(list_examinee.begin(), list_examinee.begin() + k, data.end());
    for (auto i = 0; i < data.size(); i++)
	{
        if (data[i].literature >= 1 && data[i].literature <= 200)
		{
            cout << data[i].literature << " ";
		}
	}
	vector<Examinee> result;
	for(auto i = 0; i < data.size(); i++) result.push_back(result[i]);
	return result;
}

vector<Examinee> Examinee::MergeTwoList(vector<Examinee> list1, vector<Examinee> list2)
{
	ifstream fin1;
	fin1.open("descending_Literature_1.txt");
	ifstream fin2;
	fin2.open("descending_Literature_2.txt");
	if(!fin1.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	if(!fin2.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	ofstream fout;
	fout.open("descending_Literature_3.txt");
	if(!fout.is_open())
	{
		cerr << "File can't open";
		exit(0);
	}
	vector<Examinee> list3;
	merge(list1.begin(), list1.end(), list2.begin(), list2.end(), list3.begin());
	sort(list3.rbegin(), list3.rend());
	for(auto i = 0; i < list3.size(); i++)
	{
		fout << list3[i].literature << " ";
	}
	fin1.close();
	fin2.close();
	fout.close();
	vector<Examinee> result;
	for(auto i = 0; i < list3.size(); i++) result.push_back(list3[i]);
	return result;
}

vector<Examinee> Examinee::ReadExamineeList(string file_name)
{
	ifstream fin;
	fin.open(file_name);
	if(!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	fin.ignore(EMPTY_LINE, '\n');
	while(!fin.eof())
	{
		string str;
		getline(fin, str, '\n');
		if(str.size() > 0)
		{
			Examinee exam = Examinee::ReadExaminee(str);
		}
	}
	fin.close();
	istringstream result(file_name);
	return { istream_iterator<int>(result), istream_iterator<int>() } ;
}*/

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
	}*/
	//system("pause"); 
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
	cout << "Read file successfully" << endl;
	return ll;
} 

int binarySearch(vector<float> arr, int l, int r, float x)
{
	//if (r <= l) return (x > arr[l]) ? (l + 1) : l; 
	if (l <= r) 
	{
		int mid = l + (r - l) / 2;  
		if (arr[mid] == x) return mid; 
		if (arr[mid] < x) return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

string FindExamineeByLiterature(vector<Examinee> sorted_list, float v)
{
	vector<float> liter_point;
	for (int i = 0; i < sorted_list.size(); i++) liter_point.push_back(sorted_list[i].literature);
	stringstream writer;
	int result, check=0;
	for (auto i = 0; i < liter_point.size(); i++)
	{
		result = binarySearch(liter_point, i, liter_point.size() - 1 -i, v); 
		if (result != -1)
		{
			check++; 
			writer << sorted_list[i].ID << endl;
			break;
		}
	} 
	if (check == 0) writer << "Not found";
	return writer.str();
}

void swapFloat(float &a, float &b)
{
    float temp = a;
    a = b; 
    b = temp;
}

void swapEx(Examinee &a, Examinee &b)
{
	Examinee temp = a;
	a = b;
	b = temp;
}

/*int partition(vector<Examinee>& a, int left, int right)
{
	int mid = (left + right) / 2, i = left, j = right;
	int pivot = a[mid].literature;
	while(i <= j)
	{
		while(a[i].literature < pivot) i++;
        while(a[j].literature > pivot) j--;
		if(i <= j) 
		{
            swapFloat(a[i].literature, a[j].literature);
            i++; j--;
        }
	}
	return mid;
}

void quickSort(vector<Examinee> &a, int left, int right)
{
    if(left < right) 
	{
        int mid = partition(a, left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
}

vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k)
{
	vector<Examinee> sort = list_examinee;
	quickSort(list_examinee, 0, list_examinee.size() - 1);
	vector<Examinee> result;
	for(int i = 0; i < k; i++)
	{
		result.push_back(sort[i]);
		cout << sort[i].literature << " ";
	}
	return result;
}*/

int partition(vector<Examinee>& arr, int low, int high)
{
	int pivot = arr[high].literature;
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && arr[left].literature < pivot) left++; 
		while (right >= left && arr[right].literature > pivot) right--; 
		if (left >= right) break;
		swapEx(arr[left], arr[right]); 
		left++; 
		right--; 
	}
	swapEx(arr[left], arr[high]); 
	return left; 
} 

void quickSort(vector<Examinee>& a, int left, int right) 
{
	if (left < right)
	{
		int mid = partition(a, left, right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}

vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k)
{
	quickSort(list_examinee, 0, list_examinee.size() - 1);
	vector<Examinee> result;
	int count = 0;
	for (int i = list_examinee.size()-1; i > 0; i--)
	{
		count++;
		result.push_back(list_examinee[i]);
		cout << list_examinee[i].ID << " ";
		if (count == k) break;
	}
	return result;
} 

vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2)
{
	vector<Examinee> result;
	int lenA = list1.size(), lenB = list2.size(), i = 0, j = 0;
	while(i < lenA && j < lenB)
	{
		if(i < lenA)
		{
			result.push_back(list1[i]);
			i++;
		}
		if(j < lenB)
		{
			result.push_back(list2[j]);
			j++;
		}
	}
	for(i; i < lenA; i++) result.push_back(list1[i]);
	for(j; j < lenB; j++) result.push_back(list2[j]);
	return result;
}