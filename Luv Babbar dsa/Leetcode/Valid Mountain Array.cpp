class Solution {
public:
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
        
//         case of atleast one l
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
