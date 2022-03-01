// Leetcode 
class StockSpanner 
{
    private: 
         stack<pair<int,int>>st;
    public:
    StockSpanner() 
    {
        
    }
    int next(int price) 
    {
        int ans=1;
        while(!st.empty() and st.top().first<=price)
        {
            ans+=st.top().second;
            st.pop();
        }        
        st.push({price,ans});
        return ans;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// Code Implementation from scratch 
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

// finding the next greater element to the left
void stockspan(vector<int>&arr, int n)
{
	vector<int>ans;
	stack<pair<int, int>>st;
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() and st.top().first <= arr[i])
		{
			st.pop();
		}
		if (i < n)
		{
			if (!st.empty())
			{
				ans.push_back(st.top().second);
			}
			else
			{
				ans.push_back(-1);
			}
		}
		st.push({arr[i], i});
	}

	for (int i = 0; i < ans.size(); i++)
	{
		ans[i] = i - ans[i];
	}

	for (auto x : ans)
	{
		cout << x << " ";
	}
}

int main()
{
	c_p_c();

	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	stockspan(arr, n);
	return 0;
}
