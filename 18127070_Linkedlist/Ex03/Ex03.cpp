#include"Ex03.h"

void insertFirst(Node *&head, int new_data)
{
    Node *p = new Node;
    p->data = new_data;
    p->next = head;
    head = p;
}

void insertAfter(Node *prev, int new_data)
{
    if(prev == NULL) return;
    Node *p = new Node;
    p->data = new_data;
    p->next = prev->next;
    prev->next = p;
}

void insertEnd(Node *&head, int new_data)
{
    Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    Node *last = new Node;
    last->data = new_data;
    p->next = last;
    last->next = NULL;
    if(head == NULL)
    {
        head = last;
        return;
    }
}

Node *removeFirst(Node *head)
{
    if(head == NULL) return NULL;
    Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}

Node *removeEnd(Node *head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
    return head;
}

void removeAll(Node *head)
{
    Node *p = head;
    Node *temp;
    while(p != NULL)
    {
        temp = p->next;
        delete(temp);
        p = temp;
    }
    head = NULL;
}

int sumList(Node *head)
{
    int res = 0;
    if(head == NULL) return 0;
    while(head != NULL)
    {
        res += head->data;
        head = head->next;
    }
    return res;
}

int countList(Node *head)
{
    int count = 0;
    if(head == NULL) return 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int maxList(Node *head)
{
    int max = INT_MIN;
    if(head == NULL) return NULL;
    while(head != NULL)
    {
        if(max < head->data)
        {
            max = head->data;
            head = head->next;
        }
    }
    return max;
}

void printList(Node *p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void Reverse(Node *Head, Node* &head)
{
	Node *previous;
	Node *current;
	if (Head == nullptr) return;
	previous = Head;		
	current = previous->next;	
	if (current == nullptr)
	{
		head = previous;
		return;
	}
	Reverse(current, head);
	current->next = previous;
	previous->next = nullptr;	
}

void reverse(Node *&head)
{
	Reverse(head, head);
}

void removeDuplicates(Node *p)
{
	Node *a, *b, *duplicate;
	a = p;
	while (a != NULL && a->next != NULL)
	{
		b = a;
		while (b->next != NULL)
		{
			if (a->data == b->next->data)
			{
				duplicate = b->next;
				b->next = b->next->next;
				delete(duplicate);
			}
			else 
				b = b->next;
		}
		a = a->next;
	}
}

void removeAllX(Node *&head, int x)
{
	Node *temp = head;
	Node *previous = NULL;
	while (temp != NULL && temp->data == x)
	{
		head = temp->next;    
		delete(temp);              
		temp = head;        
	}
	while (temp != NULL)
	{
		while (temp != NULL && temp->data != x)
		{
			previous = temp;
			temp = temp->next;
		}
		if (temp == NULL) return;
		previous->next = temp->next;
		delete(temp);  
		temp = previous->next;
	}
}