class Solution {
public:
    // 2 pointer appraoch
    // tc:O(n)
    // sc:o(1)
    bool validMountainArray(vector<int>& arr)
    {
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<n-1 and arr[i]<arr[i+1])
        {
            i++;
        }
        while(j>0 and arr[j-1]>arr[j])
        {
            j--;
        }
        bool ans =false;
        if(i!=n-1 and j!=0 and i==j)
        {
            ans=true;
        }
        return ans;
    }
    
    // tc:O(N)
    // sc:O(1)
    bool validMountainArray(vector<int>& arr)
    {
        // Base case 
        int n=arr.size();
        if(n<3)
        {
            return false;
        }
        
        // traversing n length array 
        int i=0;
        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                i++;
                break;
            }
            else if(arr[i]==arr[i+1])
            {
                return false;
            }
        }
        
        case of atleast one l
        if(i<2)
        {
            return false;
        }
        while(i<n)
        {
            if(arr[i-1]<=arr[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
};
