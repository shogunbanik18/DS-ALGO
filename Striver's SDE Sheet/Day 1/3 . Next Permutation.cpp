    // leetcode 
      Brute force : 
//       TC:N!*N
//       sc: O(1) only the recursion calls + O(N) for the vector ds
        // Step 1: Find all possible permutations of elements present and store them.

        // Step 2: Search input from all possible permutations.

        // Step 3: Print the next permutation present right after it.
//       Generate all possible permutaition in lexicographically sorted order and store it in vector ds 
//           Then travel through the ds and find the given sequence and return the next sequence 

        //     Printing Purmutation of string 
        // class Solution
        // {
        // 	public:
        // 	    void recur(string s,int index,int n,vector<string>&ans)
        // 	    {
        // 	        if(index==n)
        // 	        {
        // 	            ans.push_back(s);
        // 	            return;
        // 	        }
        // 	        for(int i=index;i<n;i++)
        // 	        {
        // 	            swap(s[index],s[i]);
        // 	            recur(s,index+1,n,ans);
        // 	            swap(s[index],s[i]);
        // 	        }
        // 	    }

        // 		vector<string>find_permutation(string S)
        // 		{
        // 		    vector<string>ans;
        // 		    recur(S,0,S.size(),ans);
        // 		    sort(ans.begin(),ans.end());
        // 		    return ans;
        // 		}
        // };

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



// Revision 
class Solution {
public:
    // using the most optimised appraoch 
    // using back-peak traversal algorithm 
    // intuition behind algorithm 
    // traverse from back find an element a[i]<a[i+1]
        // if(element <0) reverse all 
    // else traverse from back again and find a[l]>a[k]
    // swap them and reverse from k+1
    // resaon find the peak 
    // void nextPermutation(vector<int>& nums)
    // {
    //     int n=nums.size();
    //     int k,l;
    //     for(k=n-2;k>=0;k--)
    //     {
    //         if(nums[k]<nums[k+1])
    //         {
    //             break;
    //         }
    //     }
    //     if(k<0)
    //     {
    //         reverse(nums.begin(),nums.end());
    //     }
    //     else
    //     {
    //         for(l=n-1;l>k;l--)
    //         {
    //             if(nums[l]>nums[k])
    //             {
    //                 break;
    //             }
    //         }
    //         swap(nums[k],nums[l]);
    //         reverse(nums.begin()+k+1,nums.end());
    //     }
    // }
    
    // using c++ stl 
    // void nextPermutation(vector<int>& nums)
    // {
    //     int n=nums.size();
    //     next_permutation(nums.begin(),nums.end());
    // }
};
