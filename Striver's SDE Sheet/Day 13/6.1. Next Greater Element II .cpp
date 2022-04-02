// using the concept of nge 1
// using stack
// tc : o(n)+o(n)
// sc : o(n) stack space 
class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        stack<int>st;
        vector<int> v(n,-1);
        
        // simply ptting the elements in the stack and then traversing 
        for(int i = n-1;i>=0;i--)
        {
            st.push(nums[i]);
        }
        
        
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty() and st.top() <= nums[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                v[i] = -1;
            }
            
            else
            {
                v[i] = st.top();
            }
            
            st.push(nums[i]);
        }
        return v;
    }
};
