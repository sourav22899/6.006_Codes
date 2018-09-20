// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    count sort for 1 digit number in base N
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
#define N 10
void countsort(ll fin[],ll pri[],ll sec[],ll n)
{
    ll b[N]={0};
    ll fin[n] = {0};
    rep(i,0,n) b[sec[i]]++;
        //rep(i,0,N) cout<<b[i]<<' ';
        //cout<<'\n';
    rep(i,1,N) b[i]+=b[i-1];
        //rep(i,0,N) cout<<b[i]<<' ';
        //cout<<'\n';
    // A = sec,C = b,B = fin
    for(ll i = n-1;i > -1;i--)
    {
        fin[b[sec[i]]-1] = pri[i];
        b[sec[i]]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,k;cin>>n>>k;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    ll c[n] = {0};
    countsort(c,a,a,n);
    rep(i,0,n) cout<<c[i]<<' ';
    return 0;
}
