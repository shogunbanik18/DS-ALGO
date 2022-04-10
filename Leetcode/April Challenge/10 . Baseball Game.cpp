// using stack 
// tc : o(n)
// sc : o(n) stack space
class Solution 
{
public:
    int calPoints(vector<string>& ops) 
    {
        int n = ops.size();
        stack<int> st;
        
        for(int i = 0;i<n;i++)
        {            
            if(ops[i]=="C")
            {
                st.pop();
            }
            
            else if(ops[i]=="D")
            {
                auto a = st.top();
                st.pop();
                
                auto b = 2*a;
                
                st.push(a);
                st.push(b);
            }
            
            else if(ops[i]=="+")
            {
                auto p = st.top();
                st.pop();
                
                auto q = st.top();
                st.pop();
                
                // LIFO
                st.push(q);
                st.push(p);
                
                st.push(p+q);
            }
            
            else
            {
            
                int x = stoi(ops[i]);
                st.push(x);
            }
            
        }
        
        int ans = 0;
        while(!st.empty())
        {
            auto s = st.top();
            // cout<<s<<endl;
            st.pop();
            
            ans +=s;
        }
        
        return ans;
    }
};
