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

// tc : o(n) + o(n)
// sc : o(n)
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k)
//     {
//         vector<int> v;
        
//         ListNode * curr = head;
//         while(curr != NULL)
//         {
//             v.push_back(curr->val);
//             curr = curr ->next;
//         }
        
//         // // debug 
//         // for(auto x : v)
//         // {
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
        
//         int n = v.size();
        
//         swap(v[k-1] , v[n-k]);
        
//         // // debug 
//         // for(auto x : v)
//         // {
//         //     cout<<x<<" ";
//         // }
        
//         // converting back to linkedlist 
//         ListNode* p = new ListNode(v[0]);
//         ListNode* temp = p;
        
//         for(int i=1; i<n;i++)
//         {
//             temp->next = new ListNode(v[i]);
//             temp = temp->next; 
//         }
    
//         return p;
//     }
// };

// // optimisation using 2 pointer approach 
// // tc : o(n)
// // sc : o(1)
// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k)
//     {
//         ListNode* p = head;
        
//         ListNode* p1 = head;
//         ListNode* p2 = head;
        
//         ListNode* point1 = NULL;
        
//         while(k>1)
//         {
//             p1 = p1->next;
//             k--;
//         }
            
//         point1 = p1;
        
//         while(p1->next!=NULL)
//         {
//             p1 = p1->next;
//             p2 = p2->next;
//         }
        
//         ListNode* point2 = p2;
        
//         swap(point1->val , point2->val);
        
//         return p;
//     }
// };


// optimisation using 2 pointer approach 
// tc : o(n)
// sc : o(1)
class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* temp = head;
        
        ListNode* p1 = NULL;
        ListNode* p2 = head;
        
        int count=0;
        while(curr!=NULL)
        {
            count++;
            
            if(count==k)
            {
                p1 = curr;
            }
            
            if(count>k)
            {
                p2 = p2->next;
            }
            
            curr = curr->next;
        }
        
        // cout<<count<<endl;
        
        swap(p1->val , p2->val);
        return temp;
    }
};
