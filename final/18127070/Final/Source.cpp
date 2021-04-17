#include<iostream>
#include<fstream>
#include"Tokenizer.h"
#include<string>
#define EMPTYLINE 1000000
using namespace std;

struct student
{
	string id, note;
	float math, literature, english;
	/*student(string ID, float mat, float lit, float eng, string no)
	{
		id = ID;
		math = mat;
		literature = lit;
		english = eng;
		note = no;
	}*/
	void print()
	{
		cout << id << " " << 1.0 * (math + literature + english) / 3 << endl;
	}
	student operator = (const student& st)
	{
		this->id = st.id;
		this->math = st.math;
		this->literature = st.literature;
		this->english = st.english;
		this->note = st.note;
		return *this;
	}
	student()
	{
		id = "";
		math = literature = english = 0;
		note = "";
	}
	student(const student& st)
	{
		this->id = st.id;
		this->math = st.math;
		this->literature = st.literature;
		this->english = st.english;
		this->note = st.note;
	}
};

struct NODE
{
	student* data;
	NODE *left, *right;
	int height;
	NODE(student *s)
	{
		data = s;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

student ReadStudent(string line_info)
{
	student st;
	st.math = st.literature = st.english = 0;
	vector<string> tokens = Tokenizer::Parse(line_info, ",");
	/*for (auto i = 0; i < tokens.size(); i++) 
	{
		cout << tokens[i] << " "; 
	}*/
	//system("pause"); 
	st.id = tokens[0];
	st.math = stof(tokens[1]);
	st.literature = stof(tokens[2]);
	st.english = stof(tokens[3]);
	st.note = tokens[4];
	return st; 
}

int max(int a, int b)
{
	return (a > b)? a: b;
}

int getHeight(NODE* root)
{
	if(root == NULL) return 0;
	return root->height;
}

int getBalance(NODE* root)
{
	if(root == NULL) return NULL;
	return getHeight(root->left) - getHeight(root->right);
}

void LNR(NODE* root)
{
	if(root != NULL)
	{
		LNR(root->left);
		root->data->print();
		LNR(root->right);
	}
}

void insert(student* s, NODE*& root)
{
	if(root == NULL)
	{
		root = new NODE(s);
		return;
	}
	if((1.0 * (s->math + s->literature + s->english) / 3) < (1.0 * (root->data->math + root->data->literature + root->data->english) / 3)) insert(s, root->left);
	if((1.0 * (s->math + s->literature + s->english) / 3) == (1.0 * (root->data->math + root->data->literature + root->data->english) / 3))
	{
		if(s->math < root->data->math || s->literature < root->data->literature || s->english < root->data->english) insert(s, root->left);
		else insert(s, root->right);
	}
	else insert(s, root->right);
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int balance = getHeight(root->left) - getHeight(root->right);
	if(balance == 2)
	{
		int res = getBalance(root->left);
		if(res == 1)
		{
			NODE* temp = root->left;
			root->left = temp->right;
			temp->right = root;
			root = temp;
			root->right->height = 1 + max(getHeight(root->right->left), getHeight(root->right->right));
		}
		else if(res == -1)
		{
			NODE *temp = root->left->right;
			root->left->right = temp->left;
			temp->left = root->left;
			NODE* temp2 = root;
			temp2->left = temp->right;
			temp->right = temp2;
			root = temp;
			root->height += 1;
			root->right->height -= 2;
			root->left->height -= 1;
		}
	}
	else if(balance == -2)
	{
		int res = getBalance(root->right);
		if(res == -1)
		{
			NODE *temp = root->right;
			root->right = temp->left;
			temp->left = root;
			root= temp;
			root->left->height = 1 + max(getHeight(root->right->left), getHeight(root->right->right));
		}
		else if(res == 1)
		{
			NODE* temp = root->right->left;
			root->right->left = temp->right;
			temp->right = root->right;
			NODE* temp2 = root;
			temp2->right = temp->left;
			temp->left = temp2;
			root = temp;
			root->height += 1;
			root->left->height -= 2;
			root->right->height -= 1;
		}
	}
}

void DisplayIDs(NODE* pRoot)
{	
	ifstream fin;
	fin.open("data.txt");
	if(!fin.is_open())
	{
		cerr << "File not found";
		exit(0);
	}
	fin.ignore(EMPTYLINE, '\n'); 
	string line;
	student *st;
	while(!fin.eof())
	{
		getline(fin, line, '\n');
		if(line.size() > 0)
		{
			st = &ReadStudent(line);
			insert(st, pRoot);
			LNR(pRoot);
		}
	}
	fin.close();
}

 int Height(NODE* pRoot)
{
	if(pRoot == NULL) return 0;
	return 1 + max(Height(pRoot->left), Height(pRoot->right));
}

vector<string> SearchEqual(NODE* pRoot, float s)
{
	student st;
	s = (1.0 * (st.math + st.literature + st.english) / 3);
	if((1.0 * (pRoot->data->math + pRoot->data->literature + pRoot->data->english) / 3) > s) SearchEqual(pRoot->left, s);
	if((1.0 * (pRoot->data->math + pRoot->data->literature + pRoot->data->english) / 3) < s) SearchEqual(pRoot->right, s);
	if((1.0 * (pRoot->data->math + pRoot->data->literature + pRoot->data->english) / 3) == s) cout << pRoot->data->id << endl;
	return {};
}

vector<string> SearchGreater(NODE* pRoot, float s)
{
	student st;
	s = (1.0 * (st.math + st.literature + st.english) / 3);
	if((1.0 * (pRoot->data->math + pRoot->data->literature + pRoot->data->english) / 3) >= s) cout << pRoot->data->id << endl;
	return {};
}

int main()
{
	//NODE* AVL = NULL;
	//DisplayIDs(AVL);
	//cout << "Height of tree: "<< Height(AVL);
	//vector<string> search1 = SearchEqual(AVL, 5.0);
	//vector<string> search2 = SearchGreater(AVL, 5.0);
	return 0;
}