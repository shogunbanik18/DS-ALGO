// class Solution {
// public:
//     int minDeletion(vector<int>& nums) 
//     {
//         int n = nums.size();
//         int count=0;

//         for(int i=0;i<n-1;i++)
//         {
//             if((i+count)%2==0)
//             {
//                 if(nums[i] == nums[i + 1])
//                 {
//                     count++;
//                 }
//             }
//         }
        
//         if((n-count) %2 ==0)
//         {
//             return count;
//         }
//         else
//         {
//             return count + 1;
//         }
        
        
//     }
// };

// using stack ds
class Solution {
public:
    int minDeletion(vector<int>& nums) 
    {
        int n = nums.size();
        int count=0;

        stack<pair<int,int>>st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({nums[i],i});
            }
            
            else
            {
                if(st.top().second % 2==0 and st.top().first == nums[i] )
                {
                    continue;
                }
                
                else
                {
                    st.push({nums[i], st.top().second +1 });
                }
            }
        }
        
        if(st.size() %2 !=0)
            {
                st.pop();
            }
        
        return n - st.size();  
    }
};
