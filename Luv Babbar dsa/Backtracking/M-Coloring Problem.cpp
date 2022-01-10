// tc: O(M^N)
// sc :O(N)+o(N)
bool issafe(int node,int color[],bool graph[101][101],int n,int col)
{
    for(int k=0;k<n;k++)
    {
        if(k!=node and graph[k][node]==1 and color[k]==col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node,int color[],int m,int V,bool graph[101][101])
{
    if(node==V)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(issafe(node,color,graph,V,i))
        {
            color[node]=i;
            if(solve(node+1,color,m,V,graph))
            {
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if(solve(0,color,m,N,graph)) return true; 
    return false; 
}
