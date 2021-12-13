// TC: O(N)

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int>v;
        int l =0;
        int r=0;
        int sum=arr[0];
        while(l<n and r<n)
        {
            if(sum==s)
            {
                v.push_back(l+1);
                v.push_back(r+1);
                return v;
            }
            else if(sum>s)
            {
                sum=sum-arr[l];
                l++;
            }
             else if(sum<s)
            {
                r++;
                sum=sum+arr[r];
            }
        }
        if(v.empty())
        {
            v.push_back(-1);
        }
        return v;
    }
};
