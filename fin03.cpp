// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    insertion sort
*/
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
void isort(ll a[],ll n)
{
    rep(i,1,n)
    {
        rep(j,i,n)
        {
            if (a[j] > a[i]) swap(a[i],a[j]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    isort(a,n);
    rep(i,0,n) cout<<a[i]<<' ';
    return 0;
}
