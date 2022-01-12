    // leetcode 
      Brute force : 
//       TC:N!*N
//       sc: O(1) only the recursion calls + O(N) for the vector ds
        // Step 1: Find all possible permutations of elements present and store them.

        // Step 2: Search input from all possible permutations.

        // Step 3: Print the next permutation present right after it.
//       Generate all possible permutaition in lexicographically sorted order and store it in vector ds 
//           Then travel through the ds and find the given sequence and return the next sequence 

    Using C++ Stl 
     void nextPermutation(vector<int>& nums) 
     {
         next_permutation(nums.begin(),nums.end());
     }


    Optimized 
    // tc: o(N)+O(N)+O(N) 
    // tc: o(n)
    // sc:O(1)
    class Solution {
    public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int k;
        int l;
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};
