#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertFirst(Node *&head, int new_data);
void insertAfter(Node *prev, int new_data);
void insertEnd(Node *&head, int new_data);
Node *removeFirst(Node *head);
Node *removeEnd(Node *head);
void removeAll(Node *head);
int sumList(Node *head);
int countList(Node *head);
int maxList(Node *head);
void printList(Node *p);
void Reverse(Node *Head, Node* &head);
void reverse(Node *&head);
void removeDuplicates(Node *p);
void removeAllX(Node *&head, int x);