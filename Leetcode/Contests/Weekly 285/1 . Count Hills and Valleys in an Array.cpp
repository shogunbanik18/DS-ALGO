class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                v.push_back(nums[i]);
            }
        }
        
        v.push_back(nums[n-1]);
        
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
        
        int count=0;
    
        int  a = v.size();
        for(int i=1;i<a-1;i++)
        {
            if(v[i]>v[i-1] and v[i]>v[i+1])
            {
                count++;
            }
            else if(v[i]<v[i-1] and v[i]<v[i+1])
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};
