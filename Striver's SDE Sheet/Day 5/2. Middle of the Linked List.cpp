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
    
    // using counting method 
    ListNode* middleNode(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*temp=head;;
        ListNode*curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        int mid=(count/2)+1;
        for(int i=0;i<mid-1;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
};
