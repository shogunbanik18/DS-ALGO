class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_set<char>set;
        for(int i=0;i<jewels.size();i++)
        {
            set.insert(jewels[i]);
        }
        int count=0;
        for(int i=0;i<stones.size();i++)
        {
            if(set.find(stones[i])!=set.end())
            {
                count++;
            }
        }
        return count;
    }
    
//   Alter Approach using stl 
    int numJewelsInStones(string jewels, string stones) 
    {
        int ans=0;
        for(int i=0;i<jewels.size();i++)
        {
            ans+=count(stones.begin(),stones.end(),jewels[i]);
        }
        return ans;
    }
};
