// gfg 
class Solution{
    public:
    // Brute Force 
    // tc:o(n*n)
    // sc:o(n)
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[i])
                {
                    v.push_back(arr[j]);
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                v.push_back(-1);
            }
        }
        return v;
    } 
};


class Solution{
    public:
        optimised appraoch using stack 
    // tc:o(n)
    // sc:o(n)
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>v(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()>=arr[i])
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                {
                    v[i]=st.top();
                }
                else
                {
                    v[i]=-1;
                }
            }
            st.push(arr[i]);
        }
        return v;
    } 
};
