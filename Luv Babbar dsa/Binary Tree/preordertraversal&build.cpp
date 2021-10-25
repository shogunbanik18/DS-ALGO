#include <bits/stdc++.h>
using namespace std;

// input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

// preorder Build of Tree
// using  a function
Node *buildtree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *n = new Node(d);
    // using recursion
    n->left = buildtree();
    n->right = buildtree();
    return n;
}

// printing the tree
void printpreorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    Node *root = buildtree();
    printpreorder(root);
}