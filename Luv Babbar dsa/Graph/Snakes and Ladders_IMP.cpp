// gfg 
class Solution{
public:
    // using bfs algorithm 
    // tc: O(N)
    // sc:O(N)
    int minThrow(int N, int arr[])
    {
        unordered_map<int,int>ladders;
        unordered_map<int,int>snakes;
        // input 
        for(int i=0;i<2*N;i+=2)
        {
            if(arr[i]<arr[i+1])
            {
                ladders[arr[i]]=arr[i+1];
            }
            else if(arr[i]>arr[i+1])
            {
                snakes[arr[i]]=arr[i+1];
            }
        }
        
        int moves=0;
        queue<int>q;
        q.push(1);
        vector<bool>vis(31,false);
        vis[1]=true;
        bool found=false;
        while(!q.empty() and !found)
        {
            int sz=q.size();
            while(sz--)
            {
                int t=q.front();
                q.pop();
                
                for(int die=1;die<=6;die++)
                {
                    if(t+die==30)
                    {
                        found=true;
                    }
                    
                    if(t+die<=30 and !vis[ladders[t+die]] and ladders[t+die])
                    {
                        vis[ladders[t+die]]=true;
                        if(ladders[t+die]==30)
                        {
                            found=true;
                        }
                        q.push(ladders[t+die]);
                    }
                    
                    else if(t+die<=30 and !vis[snakes[t+die]] and snakes[t+die])
                    {
                        vis[snakes[t+die]]=true;
                        if(snakes[t+die]==30)
                        {
                            found=true;
                        }
                        q.push(snakes[t+die]);
                    }
                    
                    else if(t+die<=100 and !vis[t+die] and !snakes[t+die] and !ladders[t+die])
                    {
                        vis[t+die]=true;
                        q.push(t+die);
                    }
                }
            }
            moves++;
        }
        if(found)
        {
            return moves;
        }
        else
        {
            return -1;
        }
        // code here
    }
};





// gdb 
#include<bits/stdc++.h>
using namespace std;

// ttc :O(N)

int main()
{
    int ladders,snakes;
    cin>>ladders;
    map<int,int>lad;
    map<int,int>snak;
    for(int i=0;i<ladders;i++)
    {
        int u,v;
        cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++)
    {
        int u,v;
        cin>>u>>v;
        snak[u]=v;
    }
    
    int moves=0;
    
    // using bfs traversal algorithm 
    queue<int>q;
    q.push(1);
    bool found=false;
    vector<int>vis(101,0);
    vis[1]=true;
    while(!q.empty() and !found)
    {
        int sz=q.size();
        while(sz--)
        {
            int t=q.front();
            q.pop();
            
            for(int die=1;die<=6;die++)
            {
                if(t+die==100)
                {
                    found=true;
                }
                
                if(t+die<=100 and lad[t+die] and !vis[lad[t+die]])
                {
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100)
                    {
                        found=true;
                    }
                    q.push(lad[t+die]);
                }
                
                else if(t+die<=100 and snak[t+die] and !vis[snak[t+die]])
                {
                    vis[snak[t+die]]=true;
                    if(snak[t+die]==100)
                    {
                        found=true;
                    }
                    q.push(snak[t+die]);
                }
                
                else if(t+die<=100 and !vis[t+die] and !snak[t+die] and !lad[t+die])
                {
                    vis[t+die]=true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(found)
    {
        cout<<moves<<" ";
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    return 0;
}
