// Graph Basics 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void shogun()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// undirected
void graph_matrix()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	// debug
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}


void graph_list()
{
	int n, m;
	cin >> n >> m;

	// vector<int> adj[n+1];
	vector<pair<int, int>> adj[n + 1];


	for (int i = 0; i < m; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		// adj[u].push_back(v);
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
}

void solve_shogun()
{
	graph_matrix();
	graph_list();
	return;
}

int main()
{
	shogun();
	int t;
	cin >> t;
	while (t--)
	{
		solve_shogun();
	}
}
