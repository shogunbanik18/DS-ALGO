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
    // brute force 
    // naive approach 
    // tc:o(k*n)
    // sc:o(1)
     ListNode* rotateRight(ListNode* head, int k)
     {
         if(head==NULL or head->next==NULL)
         {
             return head;
         }
         for(int i=0;i<k;i++)
         {
             ListNode*temp=head;
             while(temp->next->next!=NULL)
             {
                 temp=temp->next;
             }
             ListNode*end=temp->next;
             temp->next=NULL;
             end->next=head;
             head=end;
         }
         return head;
     }
    
    
    // optimal approach 
    // tc:o(n)+o(n-(n%k))
    // sc:o(1)
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
    
    // tc:o(n)+o(n-(n%k))
    // sc:o(1)
    
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL or k==0)
        {
            return head;
        }
        
        ListNode*curr=head;
        int count=1;
        
        while(curr->next!=NULL)
        {
            count++;
            curr=curr->next;
            // cout<<curr->val<<" ";
        }
        curr->next=head;
        
        k=k%count;
        k= count-k;
        // cout<<count<<" "<<k<<endl;
        
        while(k--)
        {
            curr=curr->next;
        }
        ListNode*ans=curr->next;
        curr->next=NULL;
        return ans; 
    }
};
};
