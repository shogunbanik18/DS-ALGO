class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    // using the brute force approach 
    // tc: o(n*n)
    // sc:o(n)+o(n)
    // using the concept of indegree and outdegree 
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int>in(n,0);
        vector<int>out(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    out[i]++;
                    in[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==n-1 and out[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
    
    // tc: o(n)
    // sc:o(1)
    int celebrity(vector<vector<int> >& M, int n) 
    {
      int c=0;
      for(int i=1;i<n;i++)
      {
          if(M[c][i]==1)
          {
              c=i;
          }
      }
       
      for(int i=0;i<n;i++)
      {
          if(i!=c and (M[c][i]==1 or M[i][c]==0))
          {
              return -1;
          }
      }
      return c;
    }
    
    // using stack 
    // tc: o(n)
    // sc:o(n)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        while(st.size()!=1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(M[a][b]==1)
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        int ans=st.top();
        for(int i=0;i<n;i++)
        {
            if(i!=ans)
            {
                if(M[ans][i]==1 or M[i][ans]==0)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
