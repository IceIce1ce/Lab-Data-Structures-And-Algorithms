#include<iostream>
#include<climits>
using namespace std;

struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

typedef struct Node NODE;
typedef NODE* Tree;

void init(Tree& t);
void insert(Tree &t, int x);
void createTree(Tree &t);
void NLR(Tree t);
void LNR(Tree t);
void LRN(Tree t);
Node* Search(Tree t, int x);
int Height(Tree t);
void findTemporaryElement(Tree &p, Tree &q);
void Remove(Tree &t, int x);
int check(Tree t, int min, int max);
int isBST(Tree t);
int countNode(Tree t);
void printLevel(Tree t, int level);
void levelOrder(Tree t);
Node* newNode(int data);
int levelGivenNode(Tree t, int data, int level);
int level(Tree t, int data);
int countLeaf(Tree t);
int countLess(Tree t, int x);
int countGreater(Tree t, int x);