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


// alter 

#include<iostream>
using namespace std;

struct stack
{
    int arr[5];
    int top=-1;
    
    void push(int element)
    {
        if(top==4)
        {
            cout<<"Error"<<endl;
        }
        else
        {
            top++;
            arr[top]=element;
        }
    }
    
    void pop()
    {
        if(top==-1)
        {
            cout<<"Error"<<endl;
        }
        else
        {
            top--;
        }
    }
    
    void print()
    {
        for(int m=0;m<=top;m++)
        {
            cout<<arr[m]<<endl;
        }
    }
};

int main(){
    stack s;
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4) ;
    s.pop();
    s.print();
}

