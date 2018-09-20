// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    one dimensional peak finding
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
ll peak(ll a[],ll l,ll r)
{
    if(l<r)
    {
        ll mid = l+(r-l)/2;
        if(a[mid] < a[mid-1]) return peak(a,l,mid-1);
        else if(a[mid] < a[mid+1]) return peak(a,mid+1,r);
        else return a[mid];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    cout<<peak(a,0,n-1)<<'\n';
    return 0;
}
