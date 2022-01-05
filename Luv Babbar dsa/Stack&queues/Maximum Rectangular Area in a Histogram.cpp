// tc :O(N)+O(N)
// sc :O(N)+O(N)
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int>st;
        // int left[n];
        // int right[n];
        vector<int>left(n);
        vector<int>right(n);
        int i;
        for(i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            
            if(st.empty())
            {
                left[i]=0;
            }
            else
            {
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        // Your code here
    
        while(!st.empty())
        {
            st.pop();
        }
        
        for( i=n-1;i>=0;i--)
            {
                while(!st.empty() and arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                
                
                if(st.empty())
                {
                    right[i]=n-1;
                }
                else
                {
                    right[i]=st.top()-1;
                }
                st.push(i);
            }
            // Your code here
        
            long long maxA=0;
            for(i=0;i<n;i++)
            {
                maxA=max(maxA,arr[i]*(right[i]-left[i]+1));
            }
            return maxA;
    }
};
    


// it's because memory allocated of your left and right array is static i.e., in stack space and this space is used to store local and static variables and here your are overusing it .

// If you will dynamically allocate (i.e, in heap memory)the memory of your left and right array then your code will run. when your array size is huge, it is better to use dynamic array or standard containers such as vectors.
// 
