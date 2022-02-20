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
// tc:o(n)
// sc:o(n)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode*curr=head->next;
        int sum=0;
        
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        
        while(curr!=NULL)
        {
            if(curr->val==0 )
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
