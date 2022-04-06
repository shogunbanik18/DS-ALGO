// Brute Force
// tc : o(n^3)
// sc : o(1)
// class Solution 
// {
// public:
    
//     int mod = 1e9+7;
    
//     int threeSumMulti(vector<int>& arr, int target)
//     {
//         int n = arr.size();
//         int count = 0;
        
//         for(int i =0;i<n-2;i++)
//         {
//             for(int j = i+1;j<n-1;j++)
//             {
//                 for(int k = j+1;k<n;k++)
//                 {
//                     if(arr[i] + arr[j] + arr[k] == target)
//                     {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count % mod;
//     }
// };

// Optimisation using 2 pointer
// tc : o(nlogn) + o(n^2) + traversal
// sc  : o(1)
class Solution 
{
public:
    
    int mod = 1e9+7;
    
    int threeSumMulti(vector<int>& arr, int target)
    {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int count = 0;
        
        for(int i =0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            
            int sum = target - arr[i];
            
            while(j<k)
            {
                // Prob exists  here 
                if(arr[j] + arr[k] == sum)
                {
                    int count1 =1,count2=1;
                    
                    // check for duplicates 
                    while(j<k and arr[j]==arr[j+1])
                    {
                        count1++;
                        j++;
                    }
                    
                    while(j<k and arr[k]==arr[k-1])
                    {
                        count2++;
                        k--;
                    }
                    
                    // check for j and k 
                    if(j==k)
                    {
                        // second example 4c2
                        count += (count1 % mod)* ((count1-1) %mod)/2;
                        count = count %mod;
                    }
                    
                    else
                    {
                        count += (count1%mod) * (count2 %mod) ; 
                        count = count % mod;
                    }
                    
                    j++;
                    k--;
                }
                
                else if(arr[j] + arr[k] < sum)
                {
                    j++;
                }
                
                else
                {
                    k--;
                }
            }
        }
        return count % mod;
    }
};
