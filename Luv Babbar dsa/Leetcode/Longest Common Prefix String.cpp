class Solution {
public:
    
     string longestCommonPrefix(vector<string>& strs)
     {
         // tricky
         string res="";
         int n=strs.size();
         sort(strs.begin(),strs.end());
         for(int i=0;i<strs[0].size();i++)
         {
             string x=strs[0];
             string y=strs[n-1];
             if(x[i]==y[i])
             {
                 res+=x[i];
             }
             else 
             {
                 break;
             }
         }
         return res;
     }
};
