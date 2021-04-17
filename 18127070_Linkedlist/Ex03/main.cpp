#include"Ex03.h"

int main()
{
    Node *p = NULL;
    insertFirst(p, 3);
    insertFirst(p, 2);
    insertFirst(p, 1);
    insertAfter(p->next->next, 4);
    insertEnd(p, 11);
	insertEnd(p, 3);
    cout << "Linked list: ";
    printList(p);
    cout << "\nLinked list after remove first node: ";
    p = removeFirst(p);
    printList(p);
    cout << "\nLinked list after remove end node: ";
    p = removeEnd(p);
    printList(p);
    //cout << "\nLinked list after remove all node: ";
    //removeAll(p);
    //printList(p);
    cout << "\nSum of list: " << sumList(p);
    cout << "\nNumber of node: " << countList(p);
    cout << "\nMax of list: " << maxList(p);
	cout << "\nLinked list after reversing: ";
	reverse(p);
	printList(p);
	cout << "\nLinked list after removing duplicate: ";
	removeDuplicates(p);
	printList(p);
	int x = 3;
	cout << "\nLinked list after removing all key value: ";
	removeAllX(p, x);
	printList(p);
    return 0;
}