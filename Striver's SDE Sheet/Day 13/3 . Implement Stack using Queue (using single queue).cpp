// using single queue 
// tc:o(n)
// sc:o(n)
class MyStack {
public:
    queue<int>q1;
    MyStack() 
    {
       
    }
    
    void push(int x) 
    {
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() 
    {
        int res=q1.front();
        q1.pop();
        return res;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
        
        return q1.empty();
    }
};



// using  2 queues 
// tc:o(n)
// sc:o(n)+o(n)+o(n)
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() 
    {
       
    }
    
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() 
    {
        int res=q1.front();
        q1.pop();
        return res;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
        
        return q1.empty();
    }
};

