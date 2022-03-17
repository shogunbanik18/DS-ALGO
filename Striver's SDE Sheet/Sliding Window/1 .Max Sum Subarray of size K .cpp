// class Solution{   
// public:
//     int maximumSumSubarray(int K, vector<int> &Arr , int N)
//     {
//         int maxi= INT_MIN;
//         for(int i=0;i<N;i++)
//         {
//             int sum=0;
//             for(int j=i;j<i+K;j++)
//             {
//                 sum += Arr[j];
//             }
//             maxi = max(maxi,sum);
//         }
//         return maxi;
//     }
// };

// using sliding window concept 
// tc: o(n)
// sc: o(1)
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N)
    {
        int maxi= INT_MIN;
        int sum=0;
        int i=0,j=0;
        
        while(j<N)
        {
            sum += Arr[j]; 
            if(j-i+1< K)
            {
                j++;
            }
            else if(j-i+1==K)
            {
                maxi = max(maxi,sum);
                sum -= Arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};
