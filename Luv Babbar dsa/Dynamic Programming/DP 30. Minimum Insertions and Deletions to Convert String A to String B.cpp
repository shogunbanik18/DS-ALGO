// intuition : using lcs 
// using tablation dp 
// tc: o(n*m)
// sc:(n*m)
class Solution{
	public:
	int lcs(string str1,string str2)
	{
	    int n=str1.size();
	    int m=str2.size();
	    
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	    
	   // base case 
	   for(int ind2=0;ind2<=m;ind2++)
	   {
	       dp[0][ind2]=0;
	   }
	   
	   for(int ind1=0;ind1<=n;ind1++)
	   {
	       dp[ind1][0]=0;
	   }
	   
	   for(int ind1=1;ind1<=n;ind1++)
	   {
	       for(int ind2=1;ind2<=m;ind2++)
	       {
	           if(str1[ind1-1]==str2[ind2-1])
	           {
	               dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
	           }
	           else
	           {
	               dp[ind1][ind2]= 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
	           }
	       }
	   }
	   return dp[n][m];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    int lcs1 =lcs(str1,str2);
	    
	    int deletion  = n -lcs1;
	    int insertion = m- lcs1;
	    int ans= insertion+deletion;
	    return ans;
	} 
};
