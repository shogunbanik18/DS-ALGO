#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

bool containscycle(Node *head)
{
    unordered_map<Node *, bool> hashtable;
    Node *temp = head;
    while (temp != NULL)
    {
        if (hashtable.count(temp) != 0)
        {
            return true;
        }
        hashtable[temp] = true;
        temp = temp->next;
    }
    return false;
}

void insertathead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

int main()
{
    Node *a = NULL;
    insertathead(a, 1);
    insertathead(a, 2);
    insertathead(a, 3);
    insertathead(a, 4);
    insertathead(a, 5);
    insertathead(a, 6);

    Node *temp = a->next->next->next->next;
    temp->next = a->next->next;

    if (containscycle(a))
    {
        cout << "cycle found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }
    return 0;
}