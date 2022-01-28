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
    
    // iterative approach 
    // tc:o(n1+n2)
    // sc:o(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val>list2->val)
        {
            swap(list1,list2);
        }
        ListNode*res=list1;
        while(list1!=NULL and list2!=NULL)
        {
            ListNode*temp=NULL;
            while(list1!=NULL and list1->val<=list2->val )
            {
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1,list2);
        }
        return res;
    }
    
    // tc:O(n1)+O(n2)
    // sc:o(n1+n2)
    // using iterative approach 
    // extra space sorting 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode*temp=new ListNode(0);
        ListNode*dummy=temp;
       
        while(list1 and list2)
        {
            if(list1->val<=list2->val)
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
        while(list1)
        {
            temp->next=new ListNode(list1->val);
            list1=list1->next;
            temp=temp->next;
        }
         while(list2)
        {
            temp->next=new ListNode(list2->val);
            list2=list2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
