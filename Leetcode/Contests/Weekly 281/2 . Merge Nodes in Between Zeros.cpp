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
    // Efficient Solution 
    // tc:o(n)
    // sc:o(1)
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode*temp=head;
        ListNode*curr=temp->next;
    
        while(curr!=NULL)
        {
            if(curr->val!=0)
            {
                temp->val+=curr->val;
            }
            else
            {
                  if(curr->next==NULL)
                  {
                      temp->next=NULL;
                  }
                  else
                  {
                      temp->next=curr;  
                  }
                temp=curr;
            }
            curr=curr->next;
        }
        return head;
    }
    
    // tc:o(n)
    // sc:o(n)
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode*curr=head->next;
        ListNode* dummy = new ListNode(0);
        ListNode*temp=dummy;
        
        
        int sum=0;
        while(curr!=NULL)
        {
            if(curr->val==0)
            {
                temp->next=new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
            sum+=curr->val; 
            curr=curr->next;
        }
        return dummy->next;
    }
};
