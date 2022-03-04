class Solution {
public:
    // using the concept of stack and finding the next greater element
    // Storing the index in the stack 
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int>ans;
        stack<int>st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
    // using vector pair data structure 
     vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<pair<int,int>>st;
        ans[n-1]=0;
        st.push({temperatures[n-1],0});
        for(int i=n-2;i>=0;i--)
        {
            int count=1;
            while(!st.empty() and st.top().first<=temperatures[i])
            {
                int k=st.top().second;
                count+=k;
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=0;
                st.push({temperatures[i],0});
            }
            else
            {
                ans[i]=count;
                st.push({temperatures[i],count});
            }
        }
        return ans;
    }
};
