class Solution
{
public:
     int minSteps(string s, string t) 
     {
         int count1=0;
         int count2=0;
         
         map<char,int>mp1;
         map<char,int>mp2;
         
         for(auto x:s)
         {
             mp1[x]++;
         }
         
         for(auto x:t)
         {
             mp2[x]++;
         }
         
         for(auto it:mp1)
         {
             if(mp2.find(it.first)==mp2.end())
             {
                 count1+=it.second;
             }
             else
             {
                 auto it2=mp2[it.first];
                 if(it.second!=it2)
                 {
                     count1+=abs(it.second-it2);
                 }
             }
         }
         
         for(auto it:mp2)
         {
             if(mp1.find(it.first)==mp1.end())
             {
                 count1+=it.second;
             }
         }
        
         return count1;
     }
};
