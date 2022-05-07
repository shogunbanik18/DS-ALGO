#include<bits/stdc++.h>
using namespace std;

// intitalising the linkedlist
class Node
{
    public: 
    Node*prev;
    int data;
    
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
    }
};

void multiply(Node* tail, int i)
{
    Node* temp = tail;
    Node* prevnode = tail;
    int carry = 0;
    
    while(temp!=NULL)
    {
        int data = (temp->data) * i + carry;
        temp->data = data %10;
        carry = data /10;
        
        prevnode = temp;
        temp = temp->prev;
    }
    
    while(carry!=0)
    {
        Node* new1 = new Node((int)(carry%10));
        prevnode->prev = new1;
        carry = carry /10;
        prevnode = prevnode ->prev;
    }
}

void print(Node* tail)
{
    if(tail==NULL)
    {
        return ;
    }
    
    print(tail->prev);
    cout<<tail->data;
}

// void print(Node* tail)
// {
//   while(tail!=NULL)
//   {
        // cout<<tail->data<<" ";
//         tail = tail->prev;
//         
//   }
// }

int main()
{
    int n;
    cin>>n;
    
    Node tail(1);
    
    for(int i =2;i<=n;i++)
    {
        multiply(&tail,i);
    }
    
    print(&tail);
    return 0;
}
