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
    // using the concept of sum and carry 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        
        int carry=0;
        while(l1!=NULL or l2!=NULL)
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
            
            sum +=carry;
            carry=(sum)/10;
            sum=(sum)%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        if(carry!=0)
        {
            temp->next=new ListNode(carry);
            temp=temp->next;
        }
        return dummy->next;
    }
};
