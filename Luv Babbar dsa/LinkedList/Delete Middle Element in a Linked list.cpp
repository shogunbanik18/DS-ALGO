/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    
    else if (head->next == NULL)
    {
        head = NULL;
    }
    
    int count=0;
    Node*curr=head;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    
    // cout<<count<<" ";
    int mid;
    if(count%2!=0)
    {
        mid=count/2;
    }
    
    else if(count%2==0)
    {
        mid=count/2;
    }
    
    Node*prev=head;
    for(int i=0;i<mid-1;i++)
    {
        prev=prev->next;
    }
    
    prev->next=prev->next->next;
    return head;
    // Your Code Here
}



Leetcode

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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head==NULL or head->next==NULL)
        {
            return NULL;
        }
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        int mid=count/2;
        int c=0;
        ListNode*start=head;
        for(int i=0;i<mid-1;i++)
        {
            start=start->next;
        }
        start->next=start->next->next;
        return head;
    }
};
