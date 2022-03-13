/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*p= new Node(curr->val);
            p->next=curr->next;
            curr->next=p;
            curr=curr->next->next;
        }
        
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp->next->random= temp->random->next;
            }
            
            temp=temp->next->next;
        }
        
        Node*dummy = new Node(0);
        Node*a =dummy;
        Node*fast;
        Node*it=head;
        
        while(it!=NULL)
        {
            fast=it->next->next;
            a->next=it->next;
            it->next=fast;
            a=a->next;
            it=fast;
        }
        
        Node* newHead=dummy->next;
        return newHead;
    }
};

// using map 
// Brute force 
   // using Hashmap Brute Force
    // tc:o(n)+o(n)
    // sc:o(n)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) 
//     {
//         map<Node*,Node*>mp;
//         Node*curr=head;
//         while(curr!=NULL)
//         {
//             Node*a=new Node(curr->val);
//             mp[curr]=a;
//             curr=curr->next;
//         }
        
//         Node*temp=head;
//         while(temp!=NULL)
//         {
//             Node* p = mp[temp];
//             p->next =(temp->next!=NULL)?mp[temp->next]:NULL;
//             p->random = (temp->random!=NULL)?mp[temp->random]:NULL;
//             temp=temp->next;
//         }
//         return mp[head];
//     }
// };


// using concept of deep copy 
// Most optimised solution 
    // tc:o(n)+o(n)+o(n)
    // sc:o(1)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) 
//     {
//         Node*curr=head;
//         while(curr!=NULL)
//         {
//             Node*p =new Node(curr->val);
//             p->next=curr->next;
//             curr->next=p;
//             curr=curr->next->next;
//         }
        
//         Node*temp=head;
//         while(temp!=NULL)
//         {
//             if(temp->random!=NULL)
//             {
//                 temp->next->random = temp->random->next;
//             }
//             temp = temp->next->next;
//         }
        
//         // Making links
//         Node*dummy= new Node(0);
//         Node* iter=head;
//         Node* a=dummy;
//         Node* fast;
        
//         while(iter!=NULL)
//         {
//             fast=iter->next->next;
//             a->next=iter->next;
//             iter->next=fast;
//             a=a->next;
//             iter=fast;
//         }
//         return dummy->next;
//     }
// };
