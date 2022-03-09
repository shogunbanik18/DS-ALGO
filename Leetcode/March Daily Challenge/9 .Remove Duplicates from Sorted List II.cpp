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
    
    // tc: o(n)
    // sc: o(n) + o(1)
    // using Hashing 
    ListNode* deleteDuplicates(ListNode* head) 
    {
        map<int,int>mp;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            mp[curr->val]++;
            curr=curr->next;
        }
        
        // for(auto x: mp)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        ListNode*dummy=new ListNode(0);
        ListNode* temp=dummy;
        
        for(auto x: mp)
        {
            if(x.second==1)
            {
                temp->next= new ListNode(x.first);
                temp=temp->next;
            }
        }
        
        return dummy->next;
    }
    
    // tc: o(n)
    // sc:o(n)
    // skipping the duplicates
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            bool isDuplicate=false;
            while(curr->next!=NULL and curr->val==curr->next->val)
            {
                isDuplicate=true;
                curr=curr->next;
            }
            if(isDuplicate)
            {
                prev->next=curr->next;
            }
            else
            {
                prev=curr;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
    
