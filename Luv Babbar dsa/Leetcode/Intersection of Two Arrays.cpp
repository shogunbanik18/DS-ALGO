class Solution {
public:
    // tc:o(n1)+o(n2)
    // sc:o(n)+o(n)+o(1)+o(1)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>v;
        unordered_set<int>set;
        for(int i=0;i<nums1.size();i++)
        {
            set.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(set.find(nums2[i])!=set.end())
            {
                v.push_back(nums2[i]);
            }
        }
        unordered_set<int>set2;
        for(int i=0;i<v.size();i++)
        {
            set2.insert(v[i]);
        }
        vector<int>ans;
        for(auto x:set2)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
