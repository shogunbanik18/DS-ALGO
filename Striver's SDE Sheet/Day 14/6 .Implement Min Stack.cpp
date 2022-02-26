// tc:o(n)+o(n)
// sc:o(1)
// using a stack and a pair ds 
class MinStack {
public:
    stack<pair<int,int>>st;
//     MinStack() 
//     {
        
//     }
    
    void push(int val) 
    {
        int mini;
        if(st.empty())
        {
            mini=val;
        }
        else
        {
            mini=min(st.top().second,val);
        }
        st.push({val,mini});
    }
    
    void pop() 
    {
        st.pop();
    }
    
    int top() 
    {
        int ans =st.top().first;
        return ans;
    }
    
    int getMin()
    {
        int mini= st.top().second;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// tc:o(n)
// sc:o(1)
