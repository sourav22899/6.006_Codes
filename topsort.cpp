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
#define N 100000000000000000

void dfs_visit(ll s,unordered_map <ll,ll>& parent,vector <ll> adj[],vector<ll>& p,vector<ll>& top)
{
    //cout<<s<<' ';
    p.pb(s);
    for(ll v:adj[s])
    {
        if (parent.find(v) == parent.end())
        {
            parent[v] = s;
            dfs_visit(v,parent,adj,p,top);
        }
    }
    top.pb(s);
}

int main()
{
    ll v,k,x,y;cin>>v>>k;
    vector <ll> adj[v];
    // Initializing a graph by adjacency list
    rep(i,0,k)
    {
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        //adj[y].pb(x); 
    }
    // Printing the graph

    rep(i,0,v)
    {
        cout<<i<<": ";
        rep(j,0,adj[i].size()) cout<<adj[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';

    vector<ll>vertex,top;
    rep(i,0,v) vertex.pb(i);

    unordered_map<ll,ll> parent;
    // Doing a DFS
    for(ll s: vertex)
    {
        vector<ll>p;
        if(parent.find(s) == parent.end())
        {
            parent[s] = -1;
            dfs_visit(s,parent,adj,p,top);
        }
        rep(i,0,p.size()) cout<<p[i]<<' ';
        cout<<'\n';
    }
    
    for(auto & x:parent)
    {
        cout<<x.F<<" --> "<<x.S<<'\n';
    }
    
    reverse(top.begin(),top.end());
    rep(i,0,top.size()) cout<<top[i]<<' ';
    return 0;
}
