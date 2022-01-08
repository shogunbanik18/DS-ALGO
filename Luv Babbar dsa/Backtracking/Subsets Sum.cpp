class Solution
{
public:
    // tc : 2^n before sorting
    // tc: 2^n log(2^n) after sorting
    // sc: O(N)
    void find(int index,int sum,vector<int>&arr,int N,vector<int>&v)
    {
        // base case 
        if(index==N)
        {
            v.push_back(sum);
            return;
        }
        // take 
        find(index+1,sum+arr[index],arr,N,v);
        // not take 
        find(index+1,sum,arr,N,v);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;
        find(0,0,arr,N,v);
        sort(v.begin(),v.end());
        return v;
        // Write Your Code here
    }
};
