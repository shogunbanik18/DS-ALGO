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

// using extra space (Iterative Approach)
// tc: o(n)
// sc:o(n) 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL and list2!=NULL)
        {
            return list2;
        }
        if(list1!=NULL and list2==NULL)
        {
            return list1;
        }
        
        ListNode*dummy =new ListNode(0);
        ListNode*temp=dummy;
        
        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                temp->next=new ListNode(list1->val);
                list1=list1->next;
                temp=temp->next;
            }
            
            else
            {
                temp->next=new ListNode(list2->val);
                list2=list2->next;
                temp=temp->next;
            }
        }
        
        while(list1!=NULL)
        {
            temp->next=new ListNode(list1->val);
            list1=list1->next;
            temp=temp->next;
        }
        
        while(list2!=NULL)
        {
            temp->next=new ListNode(list2->val);
            list2=list2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};

// Recursive Approach 
// tc:o(n)
// sc:o(n) +o(n) stack space 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL )
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        
        ListNode*dummy=NULL;
        if(list1->val <=list2->val)
        {
            dummy= list1;
            dummy->next =mergeTwoLists(list1->next,list2);
        }
        else
        {
            dummy= list2;
            dummy->next =mergeTwoLists(list1,list2->next);
        }
        return dummy;
    }
};
