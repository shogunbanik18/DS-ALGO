// reverse sorting and 2 pointer approach
        // tc: O(K)
        // sc :O(1)
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
        {
            int p1=m-1;
            int p2=n-1;
            int i=m+n-1;
           while(p2>=0 )
           {
               if(p1>=0 and nums1[p1]>nums2[p2])
               {
                   nums1[i]=nums1[p1];
                   i--;
                   p1--;
               }
               else
               {
                   nums1[i]=nums2[p2];
                   i--;
                   p2--;
               }
           }
        } 



// // tc: O(K)
//         // sc :O(1)
//         void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//         {
//             int i=m-1;
//             int j=n-1;
//             int k=m+n-1;
//            while(i>=0 and j>=0 )
//            {
//                if(nums1[i]>nums2[j])
//                {
//                    nums1[k--]=nums1[i--];
//                }
//                else
//                {
//                    nums1[k--]=nums2[j--];
//                }
//            }
//            while(j>=0)
//            {
//                nums1[k]=nums2[j];
//                k--;
//                j--;
//            }
//         }  
