#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;++i)
#define pb push_back
typedef long long int ll;
#define max(a,b) a>=b?a:b
#define min(a,b) a>=b?b:a
#define F first
#define S second
#define N 1000000007
int main()
{
    ll v,k;
    cin>>v>>k;
    ll x,y,w;
    map < pair<ll,ll>,ll> edge;
    rep(i,0,k)
    {
        cin>>x>>y>>w;
        x--;y--;
        edge[make_pair(x,y)] = w;
        //edge[make_pair(y,x)] = w;
    }
    ll start = 0;
    ll d[v];
    rep(i,0,v) d[i]= N;
    d[start] = 0;
    rep(j,0,10)
    {
        rep(i,0,v)
        {
            for(auto & x: edge)
            {
                ll u = x.F.F;
                ll v = x.F.S;
                d[v] = min(d[v],d[u] + x.S);
            }
        }
        rep(i,0,v) cout<<d[i]<<' ';
        cout<<'\n';
    }    
    return 0;
}
