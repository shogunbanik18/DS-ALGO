// tc : o(n)
// sc: o(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        vector<int>v;
        stack<int>st;
        int i=0,j=0;
        int n=pushed.size();
        
        while(i<n and j<n)
        {
            st.push(pushed[i]);
            
            while(!st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }
    
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};

// tc: o(n)
// sc:o(1)

// using the pushed array as stack 
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        vector<int>v;
        int i=0,j=0;
        int n=pushed.size();
        
        for(auto x : pushed)
        {
            pushed[i] = x;
            i++;
            while(i>0 and  pushed[i-1]==popped[j])
            {
                i--;
                j++;
            }
        }
    
        if(i!=0)
        {
            return false;
        }
        return true;
    }
};


tc: o(n)
sc: o(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=pushed.size();
        stack<int>st;
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            
            while(!st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};
