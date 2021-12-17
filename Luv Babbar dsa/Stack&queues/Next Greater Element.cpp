// gfg 
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    // using stack 
    // TC: O(N)
    // SC:O(N)
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long>st;
        vector<long long>v;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                v.push_back(-1);
            }
            
            else
            {
                v.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
}; 
