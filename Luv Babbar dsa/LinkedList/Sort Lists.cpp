Leetcode

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
    // iterative solution 
    // using tc: O(N) and Sc: O(N)
    ListNode* sortList(ListNode* head)
    {
        // base case 
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        vector<int>v;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(),v.end());
        
        // array to linkedlist conversion 
        curr=head;
        int i=0;
        while(curr!=NULL)
        {
            curr->val=v[i];
            i++;
            curr=curr->next;
        }
        return head;
    }
};
