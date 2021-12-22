/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    // // using extra space
    // // O(N) space and time 
    Node* reverse(Node*head)
    {
        Node*curr1=head;
        Node*prev=NULL;
        Node*temp;
        while(curr1!=NULL)
        {
            temp=curr1->next;
            curr1->next=prev;
            prev=curr1;
            curr1=temp;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        Node*temp=head;
        Node*curr=reverse(head);
        while(temp!=NULL and curr!=NULL)
        {
            if(temp->data==curr->data)
            {
                return true;
                temp=temp->next;
                curr=curr->next;
            }
        }
        return false;
        //Your code here
    }
    
    
    // using tc: O(N) 
    // and space : O(1)
    Node* reverse(Node*head)
    {
        Node*curr1=head;
        Node*prev=NULL;
        Node*temp;
        while(curr1!=NULL)
        {
            temp=curr1->next;
            curr1->next=prev;
            prev=curr1;
            curr1=temp;
        }
        return prev;
    }
    
    // Finding the middle element
    Node*middle(Node*head)
    {
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    bool isPalindrome(Node *head)
    {
        // BASE CASE 
        if(head==NULL)
        {
            return true;
        }
        Node*mid=middle(head);
        Node*last=reverse(mid);
        Node*curr=head;
        while(last!=NULL)
        {
            if(last->data!=curr->data)
            {
                return false;
            }
            last=last->next;
            curr=curr->next;
        }
        return true;
    }
};




// leetcode 
 // using vector 
    // tc: O(N)
    // sc: O(N)
    bool isPalindrome(ListNode* head) 
    {
        vector<int>v;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        bool flag=true;
        int i=0;
        int j=v.size()-1;
        while(i<=j)
        {
            if(v[i]!=v[j])
            {
                flag=false;
            }
            i++;
            j--;
        }
        
        if(flag==false)
        {
            return false;
        }
        return true;  
    }
    
