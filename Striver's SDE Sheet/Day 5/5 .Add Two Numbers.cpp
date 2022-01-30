// Add Two Numbers
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
    // tc:o(max(l1,l2)) maximum of their length
    // sc:o(n) for extra linked list 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        int carry=0;
        while(l1!=NULL or l2!=NULL or carry!=0)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=newnode;            
        }
        return dummy->next;
    }
};
