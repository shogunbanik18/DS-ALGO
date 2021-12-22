void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1)
    {
        return -1;
    }
    return arr[top--];
    // Your Code       
}
