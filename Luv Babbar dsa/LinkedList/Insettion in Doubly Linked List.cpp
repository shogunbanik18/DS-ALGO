DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data)
{
    DoublyLinkedListNode* a = new DoublyLinkedListNode(data);
    
    // when list is empty 
    if(llist==NULL)
    {
        return a;
    }    
    
    // at the beginning 
    if(a->data <= llist->data)
    {
        a->next = llist;
        llist->prev = a;
        llist = a;
    }
    
    else
    {
        DoublyLinkedListNode* temp = llist;
        
        while(a->data > temp->data)
        {
            // insertion at the end 
            if(temp->next==NULL)
            {
                temp->next = a;
                a->prev = temp;
                return llist;
            }
            
            temp = temp->next;
        }
        
        temp->prev->next = a;
        a->prev = temp->prev;
        a->next = temp;
        temp->prev = a;
    }
    return llist;
}
