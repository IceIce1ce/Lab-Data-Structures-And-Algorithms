#include"1.1.h"

void init(Tree& t)
{
    t = NULL;
}

void insert(Tree &t, int x)
{
    if(t == NULL)
    {
        NODE *temp = new NODE;
        temp->data = x;
        temp->pLeft = temp->pRight = NULL;
        t = temp;
    }
    else
    {
        if(t->data > x)
        {
            insert(t->pLeft, x);
        }
        else if(t->data < x)
        {
            insert(t->pRight, x);
        }
    }
}

void createTree(Tree &t)
{
    init(t);
    int choice;
    do
    {
        cout << "1. Create node";
        cout << "\n0. Quit";
        cout << "\nYour choice: ";
        cin >> choice;
        if(choice == 1)
        {
            int x;
            cout << "Enter node: ";
            cin >> x;
            insert(t, x);
        }
    }while(choice != 0);
}

void NLR(Tree t)
{
    if(t != NULL)
    {
        cout << t->data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void LNR(Tree t)
{
    if(t != NULL)
    {
        LNR(t->pLeft);
        cout << t->data << " ";
        LNR(t->pRight);
    }
}

void LRN(Tree t)
{
    if(t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->data << " ";
    }
}

Node* Search(Tree t, int x)
{
    if(t == NULL) return NULL;
    if(t->data > x)
    {
        Search(t->pLeft, x);
    }
    else if(t->data < x)
    {
        Search(t->pRight, x);
    }
    return t;
}

int Height(Tree t)
{
    if(t == NULL) return 0;
    int a = Height(t->pLeft);
    int b = Height(t->pRight);
    if(a > b) return a + 1;
    else return b + 1;
}

void findTemporaryElement(Tree &p, Tree &q)
{
    if(q->pLeft != NULL)
    {
        findTemporaryElement(p, q->pLeft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->pRight;
    }
}

void Remove(Tree &t, int x)
{
    if(t == NULL) return;
    if(t->data > x)
    {
        Remove(t->pLeft, x);
    }
    else if(t->data < x)
    {
        Remove(t->pRight, x);
    }
    else
    {
        Node *temp = t;
        if(t->pLeft == NULL)
        {
            t = t->pRight;
        }
        else if(t->pRight == NULL)
        {
            t = t->pLeft;
        }
        else
        {
            findTemporaryElement(temp, t->pRight);
        }
        delete temp;
    }
}

int check(Tree t, int min, int max)
{
    if(t == NULL) return 1;
    if(t->data < min || t->data > max) return 0;
    return check(t->pLeft, min, t->data - 1) && check(t->pRight, t->data + 1, max);
}

int isBST(Tree t)
{
    return check(t, INT_MIN, INT_MAX);
}

int countNode(Tree t)
{
    if(t == NULL) return 0;
    int count = 0;
    if(t->pLeft && t->pRight) count++;
    count += countNode(t->pLeft) + countNode(t->pRight);
    return count;
}

void printLevel(Tree t, int level)
{
    if(t == NULL) return;
    if(level == 1) cout << t->data << " ";
    else if(level > 1)
    {
        printLevel(t->pLeft, level - 1);
        printLevel(t->pRight, level - 1);
    }
}

void levelOrder(Tree t)
{
    int level = Height(t);
    for(int i = 1; i <= level; i++) printLevel(t, i);
}

Node* newNode(int data)
{
    Tree t = new Node();
    t->data = data;
    t->pLeft = NULL;
    t->pRight = NULL;
    return t;
}

int levelGivenNode(Tree t, int data, int level)
{
    if(t == NULL) return NULL;
    if(t->data == data) return level; //default level of tree
    int result = levelGivenNode(t->pLeft, data, level + 1);
    if(result != 0) return result; //if found in left subtree
    result = levelGivenNode(t->pRight, data, level + 1);
    return result; //if found in right subtree
}

int level(Tree t, int data)
{
    return levelGivenNode(t, data, 1);
}

int countLeaf(Tree t)
{
    if(t == NULL) return 0;
    if(t->pLeft == NULL && t->pRight == NULL) return 1;
    else return (countLeaf(t->pLeft) + countLeaf(t->pRight));
}

int countLess(Tree t, int x)
{
    if(t == nullptr) return 0;
    if(t->data < x) return 1 + countLess(t->pLeft, x) + countLess(t->pRight, x);
    else return countLess(t->pLeft, x) + countLess(t->pRight, x);
    if(t->data > x) return countLess(t->pLeft, x);
}

int countGreater(Tree t, int x)
{
    if(t == nullptr) return 0;
    if(t->data > x) return 1 + countGreater(t->pLeft, x) + countGreater(t->pRight, x);
    else return countGreater(t->pLeft, x) + countGreater(t->pRight, x);
    if(t->data < x) return countGreater(t->pLeft, x);
}