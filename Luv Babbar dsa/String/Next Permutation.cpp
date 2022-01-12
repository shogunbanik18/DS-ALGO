class Solution{
public:
    // tc:O(n)+O(n)+O(n)
    // sc:O(1)
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        int k,l;
        for(k=N-2;k>=0;k--)
        {
            if(arr[k]<arr[k+1])
            {
                break;
            }
        }
        
        if(k<0)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        {
            for(l=N-1;l>k;l--)
            {
                if(arr[l]>arr[k])
                {
                    break;
                }
            }
            swap(arr[k],arr[l]);
            reverse(arr.begin()+k+1,arr.end());
        }
        return arr;
        // code here
    }
};
