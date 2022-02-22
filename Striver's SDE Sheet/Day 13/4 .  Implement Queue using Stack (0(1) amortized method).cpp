// queue using 2 stacks
// tc:o(1) amortised 
// sc:o(n)+o(n)

class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        input.push(x);
    }
    
    int pop() 
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ele=output.top();
        output.pop();
        return ele;
    }
    
    int peek() 
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ele=output.top();
        return ele;
    }
    
    bool empty() 
    {
        return output.empty() && input.empty(); 
    }
};

// Queue using 2 stacks 
// tc:o(n)
// sc:o(n)+o(n)

// Algo : 
// 1. s1 to s2
// 2. x to s1
// 3. s2 to s1

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }   
    }
    
    int pop() 
    {
        int res=s1.top();
        s1.pop();
        return res;
    }
    
    int peek() 
    {
        int a =s1.top();
        return a;
    }
    
    bool empty() 
    {
        if(s1.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
