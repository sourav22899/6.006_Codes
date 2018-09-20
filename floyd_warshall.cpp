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
    ll v,m;cin>>v>>m;
    ll adj[v][v];
    rep(i,0,v)
    {
        rep(j,0,v)
        {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = N;
        }
    }
    ll x,y,w;
    rep(i,0,m)
    {
        cin>>x>>y>>w;
        x--;y--;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    rep(k,0,v)
    {
        rep(i,0,v)
        {
            rep(j,0,v)
            {
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[j][k]);
            }
        }
    }
    rep(i,0,v)
    {
        rep(j,0,v)
        {
            cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
