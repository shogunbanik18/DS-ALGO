class Solution
{
public:
//     using otimal solution 
//   using recursion 
//   tc:o(2^n)
//   sc:o(2^n)
    void f(int ind,int sum,vector<int>&arr,int N,vector<int>&v)
    {
        if(ind==N)
        {
            v.push_back(sum);
            return ;
        }
        f(ind+1,sum+arr[ind],arr,N,v);
        f(ind+1,sum,arr,N,v);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;
        f(0,0,arr,N,v);
        sort(v.begin(),v.end());
        return v;
    }
};
