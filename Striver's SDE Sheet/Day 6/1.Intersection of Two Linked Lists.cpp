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
    // Brute force 
    // tc:O(M*N)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curr2=headB;
        while(curr2!=NULL)
        {
            ListNode *curr1=headA;
            while(curr1!=NULL)
            {
                if(curr1==curr2)
                {
                    return curr1;
                }
                curr1=curr1->next;
            }
            curr2=curr2->next;
        }
        return NULL;
    }
     
    // tc:O(M+N)
    // sc:o(N)
    // using hashing using unordered set 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curr1=headA;
        ListNode *curr2=headB;
        unordered_set<ListNode *>set;
        while(curr1!=NULL)
        {
            set.insert(curr1);
            curr1=curr1->next;
        }
        while(curr2!=NULL)
        {
            if(set.find(curr2)!=set.end())
            {
                return curr2;
            }
            curr2=curr2->next;
        }
        return NULL;
    }
    
    // optimal solution 1 
    // Longer Method 
    // using the concept of Difference and Traversal 
    // tc:O(M)+o(M-N)+o(N)
    // sc:o(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *dummy1=headA;
        ListNode *dummy2=headB;
        int count1=0,count2=0;
        while(dummy1!=NULL)
        {
            count1++;
            dummy1=dummy1->next;
        }
         while(dummy2!=NULL)
        {
            count2++;
            dummy2=dummy2->next;
        }
        int diff;
        if(count1>count2)
        {
            diff=count1-count2;
        }
        else
        {
            diff=count2-count1;
        }
        dummy1=headA;
        dummy2=headB;
        if(count1>count2)
        {
            for(int i=0;i<diff;i++)
            {
                dummy1=dummy1->next;
            }
        }
        else
        {
            for(int i=0;i<diff;i++)
            {
                dummy2=dummy2->next;
            } 
        }
        
        while(dummy1!=NULL and dummy2!=NULL)
        {
            if(dummy1==dummy2)
            {
                return dummy1;
            }
            dummy1=dummy1->next;
            dummy2=dummy2->next;
        }
        return NULL;
    }
    
    // optimal solution 2 
    // Shorter Method 
    // using the concept of Alignment difference
    // tc:O(M)+o(M-N)+o(N)
    // tc:~ o(2m)
    // sc:o(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *dummy1=headA;
        ListNode *dummy2=headB;
        while(dummy1!=NULL or dummy2!=NULL)
        {
            if(dummy1==NULL)
            {
                dummy1=headB;
            }
            if(dummy2==NULL)
            {
                dummy2=headA;
            }
            if(dummy1==dummy2)
            {
                return dummy1;
            }
            dummy1=dummy1->next;
            dummy2=dummy2->next;
        }
        return NULL;
    }
    
    // tc:~ o(2m)
    // sc:o(1)
    // striver's optimal solution 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==NULL or headB==NULL)
        {
            return NULL;
        }
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b)
        {
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    // }
};
