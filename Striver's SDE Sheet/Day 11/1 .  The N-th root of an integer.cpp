// Leetcode sqrt(x)
class Solution {
public:
    // using stl 
    // int mySqrt(int x)
    // {
    //     int y= sqrt(x);
    //     return y;
    // }
    
    // using Binary Search 
    int mySqrt(int x) 
    {
       if(x==0)
       {
           return 0;
       }
       int low=1;
       int high=x;
       int ans;
       while(low<=high)
       {
           int mid =low+(high-low)/2;
           if(mid<=x/mid)
           {
               ans=mid;
               low=mid+1;
           }
           else
           {
               high=mid-1;
           }
       }
       return ans;
    }
};


// Using General method 
double multiply(double number,int n)
{
    double ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*number;
    }
    return ans;
}

double findNthRootOfM(int n, int m) 
{
    double low=1;
    double high=m;
    double eps =1e-15;
    
    while((high-low)>eps)
    {
        double mid =(low+high)/2.0;
        if(multiply(mid,n)<m)
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
    double ans =low;
    return ans;
}


// using power function 
cout<<pow(m ,(double)1.0/(double)n);


// Sublime 
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define PI 3.14
#define _USE_MATH_DEFINES
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll, ll>
#define pi pair<int, int>
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define endl "\n"
#define debug(x) cout << #x << " -> " << x << "\n";
const ll mod = 1000000007;
const ll MOD = 998244353;
const ll inf = 1e18;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

double checkpossible(int n, int m, int mid)
{
	double ans = 1.0;
	for (int i = 1; i <= n; i++)
	{
		ans = ans * mid;
	}
	return ans;
}

void findroot(int n, int m)
{
	double low = 1;
	double high = m;
	double eps = 1e-6;
	while ((high - low) > eps)
	{
		double mid = low + (high - low) / 2.0;
		if (checkpossible(n, m, mid) >= m)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	cout << low << endl;
}

int main()
{
	c_p_c();

	int n, m;
	cin >> n >> m;
	findroot(n, m);
	return 0;
}

