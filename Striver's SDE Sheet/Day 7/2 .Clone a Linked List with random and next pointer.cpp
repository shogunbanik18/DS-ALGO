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
    // using Hashmap Brute Force
    // tc:o(n)+o(n)
    // sc:o(n)
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*,Node*>Hashmap;
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*a= new Node(curr->val);
            Hashmap[curr]=a;
            curr=curr->next;
        }
        Node*temp=head;
        while(temp!=NULL)
        {
            Node*p=Hashmap[temp];
            p->next =(temp->next!=NULL)?Hashmap[temp->next]:NULL;
            p->random =(temp->random!=NULL)?Hashmap[temp->random]:NULL;
            temp=temp->next;
        }
        return Hashmap[head];
    }
    
    // Most optimised solution 
    // tc:o(n)+o(n)+o(n)
    // sc:o(1)
    Node* copyRandomList(Node* head)
    {
        Node*curr=head;
        while(curr!=NULL)
        {
            Node*p=new Node(curr->val);
            p->next=curr->next;
            curr->next=p;
            curr=curr->next->next;
        }
        
        Node*temp=head;
        while(temp!=NULL)
        {
            // edge case 
            if(temp->random!=NULL)
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        
        // making the links
        Node*dummy=new Node(0);
        Node*iter=head;
        Node*a=dummy;
        Node*fast;
        while(iter!=NULL)
        {
            fast=iter->next->next;
            a->next=iter->next;
            iter->next=fast;
            a=a->next;
            iter=fast;
        }
        return dummy->next;
    }  
};
