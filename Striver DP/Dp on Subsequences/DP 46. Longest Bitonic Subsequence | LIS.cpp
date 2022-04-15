#include<bits/stdc++.h>
// using the dp concept of lis 

int longestBitonicSequence(vector<int>& arr, int n) 
{   
	vector<int> dp1(n,1),dp2(n,1);
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j] <arr[i] and 1 + dp1[j] > dp1[i] )
			{
				dp1[i] = 1+dp1[j];
			}
		}
	}
	
// 	vector<int>v ;
// 	for(int i =n-1;i>=0;i--)
// 	{
// 		v.push_back(arr[i]);
// 	}
// 	for(int i = 0;i<n;i++)
// 	{
// 		for(int j = 0;j<i;j++)
// 		{
// 			if(v[j] <v[i] and 1 + dp2[j] > dp2[i] )
// 			{
// 				dp2[i] = 1+dp2[j];
// 			}
// 		}
// 	}
	
// 	reverse(dp2.begin(),dp2.end());
	
	for(int i = n-1 ;i >=0;i--)
	{
		for(int j =n-1;j>i;j--)
		{
			if(arr[j] <arr[i] and 1 + dp2[j] > dp2[i] )
			{
				dp2[i] = 1+dp2[j];
			}
		}
	}
	
	
	int maxi = 0;
	for(int i = 0;i<n;i++)
	{
		int ans = dp1[i] + dp2[i] -1;
		maxi = max(maxi,ans);
	}
	return maxi;
} 
