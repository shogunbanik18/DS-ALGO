lass Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> v;
        stack<long long>s;
        s.push(arr[n-1]);
        v.push_back(-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() and s.top()<=arr[i])
            {
                s.pop();
            }
            
            if(s.empty()==true)
            {
                s.push(arr[i]);
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
                s.push(arr[i]);
            }
        }
        reverse(v.begin(),v.end());
        return v;
        // Your code here
    }
};
