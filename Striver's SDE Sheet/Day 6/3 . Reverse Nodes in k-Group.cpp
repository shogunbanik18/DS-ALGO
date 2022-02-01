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
    // tc:o(n/k)*k
    // tc:o(n)
    // sc:o(1)
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
       
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr=dummy;
        ListNode*temp=dummy;
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        while(count>=k)
        {
            curr=prev->next;
            temp=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=temp->next;
                temp->next=prev->next;
                prev->next=temp;
                temp=curr->next;
            }
            count-=k;
            prev=curr;
        }
        return dummy->next;
    }
};
