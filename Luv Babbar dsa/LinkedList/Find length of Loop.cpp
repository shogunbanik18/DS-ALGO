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

//Function to find the length of a loop in the linked list.
// using tortoise hare method 
int countNodesinLoop(struct Node *head)
{
    Node*slow=head;
    Node*fast=head;
    bool flag=false;
    
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            flag=true;
            break;
        }
    }
    
    if(flag)
    {
        int count=1;
        slow=slow->next;
        while(slow!=fast)
        {
            slow=slow->next;
            count++;
        }
        return count;
    }
    
    else
    {
        return 0;
    }
}
