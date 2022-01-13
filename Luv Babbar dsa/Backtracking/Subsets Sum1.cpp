class Solution
{
public:
//   tc:O(2^N)
//   sc:O(2^N) Axiliary space
     void recur(vector<int>&arr,vector<int>&ans,int sum,int ind,int n)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        //  take
        recur(arr,ans,sum+arr[ind],ind+1,n);
        // not take 
        recur(arr,ans,sum,ind+1,n);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        recur(arr,ans,0,0,N);
        return ans;
        // Write Your Code here
    }
};
