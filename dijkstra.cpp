// use ...\> g++ <name>.cpp -std=c++11 for compiling.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i = n;i < m;++i)
#define pb push_back
typedef long long int ll;
#define max(a,b) a >= b ? a:b
#define min(a,b) a >= b ? b:a
#define F first
#define S second
#define N 10000000000000000
typedef pair<ll,ll> lpair;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll v,e,x,y,w,s;cin>>v>>e>>s;
    vector<lpair> adj[v];
    rep(i,0,e)
    {
        cin>>x>>y>>w;
        x--;y--;
        adj[x].pb(make_pair(y,w));
        adj[y].pb(make_pair(x,w));
    }
    priority_queue < lpair,vector <lpair> ,greater <lpair>> pq;
    vector<ll>d;
    rep(i,0,v) d.pb(N);
    d[s] = 0;
    unordered_map<ll,ll> parent;
    //rep(i,0,v) parent[i] = -1;
    parent[s] = -1;
    pq.push(make_pair(0,s));
    while(pq.empty() == false)
    {
        ll u = pq.top().S;
        pq.pop();
        for(auto x:adj[u])
        {
            if(d[x.F] > d[u] + x.S)
            {
                d[x.F] = d[u] + x.S;
                parent[x.F] = u;
                pq.push(make_pair(d[x.F],x.F));
            }
        }
    }
    for(auto x:parent)
    {
        cout<<x.F+1<<" --> "<<x.S+1<<'\n'; 
    }
    rep(i,0,v)cout<<i+1<<": "<<d[i]<<'\n';
    return 0;
}
