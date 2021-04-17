#include"1.1.h"

int main()
{
    /*Tree t;
    createTree(t);
    cout << "NLR: ";
    NLR(t);
    cout << "\nLNR: ";
    LNR(t);
    cout << "\nLRN: ";
    LRN(t);
    int x;
    cout << "\nSearch node: ";
    cin >> x;
    Node *temp = Search(t, x);
    if(temp == NULL) cout << "Not found x";
    else cout << "Found x";
    cout << "\nHeight of tree: " << Height(t);
    int y;
    cout << "\nDelete node: ";
    cin >> y;
    Remove(t, y);
    cout << "Tree after deleting: ";
    NLR(t);
    if(isBST(t)) cout << "\nTree is bst";
    else cout << "\nTree is not bst";
    cout << "\nNumber of node: " << countNode(t);*/
    Tree t = newNode(10);
    t->pLeft = newNode(5);  
    t->pRight = newNode(50);  
    t->pLeft->pLeft = newNode(1);  
    t->pRight->pLeft = newNode(40);  
    t->pRight->pRight = newNode(100); 
    cout << "\nLevel Order traversal: ";  
    levelOrder(t);  
    /*for(int i = 1; i <= 5; i++)
    {
        int result = level(t, i);
        if(result) cout << "\nlevel of node " << i << " is: " << level(t, i);
        else cout << "\nNode " << i << " not found in tree";
    }
    cout << "\nLeaf node count: " << countLeaf(t);*/
    cout << "\nNumber of node less than x: " << countLess(t, 3);
    cout << "\nNumber of node greater than x: " << countGreater(t, 101);
    return 0;
}