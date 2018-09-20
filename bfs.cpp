/// use ...\> g++ bfs.cpp -std=c++11 for compiling.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i = n;i < m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a >= b ? a:b
#define min(a,b) a >= b ? b:a
#define F first
#define S second
#define N 1000000007
int main()
{
    ll v,k,n,m;cin>>v>>k;
    // Initializing a graph 
    vector <ll> adj[v];
    rep(i,0,k)
    {
        cin>>n>>m;
        n--;m--;
        adj[n].pb(m);
        adj[m].pb(n);
    }    
    rep(i,0,k)
    {
        cout<<i<<':'<<' ';
        rep(j,0,adj[i].size()) cout<<adj[i][j]<<' ';
        cout<<endl;
    }
    
    ll start = 0;
    unordered_map <ll,ll> parent;
    unordered_map <ll,ll> level;
    vector<ll> frontier;
    frontier.pb(start);
    parent[start] = -1;
    level[start] = 0;
    ll i = 1;
    // Doing a BFS
    while (frontier.empty() == false)
    {
        vector <ll> n;
        rep(u,0,frontier.size())
        {
            rep(v,0,adj[frontier[u]].size())
            {
                if (level.find(adj[frontier[u]][v]) == level.end())
                {
                    level[adj[frontier[u]][v]] = i;
                    parent[adj[frontier[u]][v]] = frontier[u];
                    n.pb(adj[frontier[u]][v]);
                }
            }
        }
        frontier = n;
        i++;
    }
    for(auto & x:parent)
    {
        cout<<x.F <<" --> "<<x.S<<endl;
    }
    cout<<endl;
    for(auto & x:level)
    {
        cout<<x.F <<" --> "<<x.S<<endl;
    }
    return 0;
}
