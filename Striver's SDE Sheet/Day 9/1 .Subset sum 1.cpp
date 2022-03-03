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


class Solution
{
public:   
    void f(int ind,vector<int>&arr,vector<int>&ds,int sum)
    {
        if(ind==-1)
        {
            // ds.push_back(sum+arr[ind]);
            ds.push_back(sum);
            return ;
        }
        f(ind-1,arr,ds,sum+arr[ind]);
        f(ind-1,arr,ds,sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        vector<int>ds;
        f(N-1,arr,ds,sum);
        return ds;
    }
};
