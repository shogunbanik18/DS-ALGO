/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // using brute force 
    // using hashing 
    // tc:o(n)
    // sc:o(n)
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *>set;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(set.find(curr)!=set.end())
            {
                return curr;
            }
            set.insert(curr);
            curr=curr->next;
        }
        return NULL;
    }
    
    // Optimal Approach 
    // tc:o(n)
    // sc:o(1)
    // using floyd's cycle detection algorithm 
    // Hare Tortoise Method 
     ListNode *detectCycle(ListNode *head)
     {
         if(head==NULL or head->next==NULL)
         {
             return NULL;
         }
         ListNode *slow=head;
         ListNode *fast=head;
         ListNode *entry=head;
         while(fast->next!=NULL and fast->next->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
             {
                 while(entry!=slow)
                 {
                     slow=slow->next;
                     entry=entry->next;
                 }
                 return entry;
             }
         }
         return NULL;
     }
    
    
    // Intuition behind the approach
//     fast pointer travels twice the distance of slow pointer 
//     d(fast)=2*d(slow)
//     l1+l2+nc=2*(l1+l2)
//     nc=l1+l2
//     l1=(nc-l2)
//     l1 is travelled by the entry pointer 
//     nc-l2 is travelled by the slow pointer after cycle detection      
};
