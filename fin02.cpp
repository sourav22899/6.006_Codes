// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    two dimensional peak finding
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
ll peak_two(ll *a,ll l,ll r,ll m)
{
    ll mid = l+(r-l)/2;
    ll temp = 0;
    rep(i,0,m)
    {
        if(*((a+i*(r-l+1))+mid) > *((a+temp*(r-l+1))+mid)) temp = i;
    }
    if(*((a+temp*(r-l+1))+mid-1) > *((a+temp*(r-l+1))+mid)) return peak_two((ll*)a,l,mid-1,m);
    else if(*((a+temp*(r-l+1))+mid+1) > *((a+temp*(r-l+1))+mid)) return peak_two((ll*)a,mid+1,r,m);
    else return *((a+temp*(r-l+1))+mid);
    //if(*((a+temp*n)+mid) > *((a+temp*n)+mid) && *((a+temp*n)+mid))
}
ll peak(ll a[],ll l,ll r)
{
    if(l<r)
    {
        ll mid = l+(r-l)/2;
        if(a[mid] < a[mid-1]) return peak(a,l,mid-1);
        else if(a[mid] < a[mid+1]) return peak(a,mid+1,r)
        else return a[mid];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll m,n;cin>>m>>n;
    ll a[m][n];
    rep(i,0,m) 
    rep(j,0,n) cin>>a[i][j];
    cout<<peak_two((ll*)a,m,n)<<'\n';
    return 0;
}
