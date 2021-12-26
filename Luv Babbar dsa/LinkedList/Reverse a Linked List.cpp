// / Iterative C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}

// void reverse(node *&head)
// {
//     node *c = head;
//     node *p = NULL;
//     node *temp;

//     while (c != NULL)
//     {
//         temp = c->next;
//         c->next = p;
//         p = c;
//         c = temp;
//     }
//     head = p;
// }

// int main()
// {
//     node *head;
//     cin >> head;
//     cout << head;
//     reverse(head);
//     cout << head;
// }


Leet code 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};
