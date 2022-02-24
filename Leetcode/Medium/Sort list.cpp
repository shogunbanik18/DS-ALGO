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
// class Solution {
// public:
//     // tc:o(nlogn)
//     // sc:o(n)+o(n)
//     ListNode* sortList(ListNode* head) 
//     {
//         vector<int>v;
//         ListNode* curr=head;
//         while(curr!=NULL)
//         {
//             v.push_back(curr->val);
//             curr=curr->next;
//         }
//         sort(v.begin(),v.end());
//         ListNode*dummy=new ListNode(0);
//         ListNode*temp=dummy;
//         for(int i=0;i<v.size();i++)
//         {
//             temp->next=new ListNode(v[i]);
//             temp=temp->next;
//         }
//         return dummy->next;
//     }
// };

// using mergesort
class Solution {
public:
    // tc:o(nlogn)
    // sc:o(1)
    ListNode*mergeList(ListNode*l1,ListNode*l2)
    {
        ListNode*ptr=new ListNode(0);
        ListNode*curr=ptr;
        
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1!=NULL)
        {
            curr->next= l1;
            l1=l1->next;
        }
        
        if(l2!=NULL)
        {
            curr->next= l2;
            l2=l2->next;
        }
        return ptr->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        
        ListNode*temp=NULL;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        temp->next=NULL;
        
        ListNode*l1 =sortList(head);
        ListNode*l2 =sortList(slow);
        
        return mergeList(l1,l2);
    }
};
