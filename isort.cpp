#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a>=b?a:b
#define min(a,b) a>=b?b:a
#define F first
#define S second
////////insertion sort/////////
void isort(ll a[],ll n)
{
  rep(j,1,n)
  {
    ll x=a[j];
    ll i=j-1;
    while(i>=0 && a[i]<x)
    {
      a[i+1]=a[i];i--;
    }
    a[i+1]=x;
  }
}
int main()
{
  ll n;cin>>n;ll a[n];
  rep(i,0,n) cin>>a[i];
  /*rep(j,1,n)
  {
    ll x=a[j];
    ll i=j-1;
    while(i>=0 && a[i]<x)
    {
      a[i+1]=a[i];i--;
    }
    a[i+1]=x;
  }*/
  isort(a,n);
  rep(i,0,n) cout<<a[i]<<' ';
  return 0;
}
