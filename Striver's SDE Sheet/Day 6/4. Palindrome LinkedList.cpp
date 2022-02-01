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
    // // brute force
    // // tc:o(n)+o(n)
    // // sc:o(n)
    bool isPalindrome(ListNode* head)
    {
        ListNode*curr=head;
        vector<int>v;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        int l=0,h=v.size()-1;
        while(l<=h)
        {
            if(v[l]!=v[h])
            {
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    
    // 2nd brute force 
    // tc:o(n)
    // sc:o(n)
    ListNode* reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*temp;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode*curr1=head;
        ListNode*dummy=new ListNode(0);
        ListNode*newhead=dummy;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            dummy->next= new ListNode(temp->val);
            dummy=dummy->next;
            temp=temp->next;
        }
        ListNode*curr2=reverse(newhead->next);
        while(curr1!=NULL and curr2!=NULL)
        {
            if(curr1->val!=curr2->val)
            {
                return false;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;
    }
    
    // optimised code 
    // tc:o(n/2)+o(n/2)+o(n/2)+o(n/2)+o(n/2)
    // sc:o(1)
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*p;
        while(curr!=NULL)
        {
            p=curr->next;
            curr->next=prev;
            prev=curr;
            curr=p;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        bool ans=true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*dummy=head;
        ListNode*temp=reverse(slow->next);
        slow=temp;
        while(slow!=NULL)
        {
            if(slow->val!=dummy->val)
            {
                ans=false;
            }
            dummy=dummy->next;
            slow=slow->next;
        }
        return ans;
    }
};
