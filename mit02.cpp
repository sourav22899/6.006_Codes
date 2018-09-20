#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a>=b?a:b
#define min(a,b) a>=b?b:a
#define F first
#define S second
#define N 1000000007
void ins_sort(ll a[],ll n)
{
  rep(i,0,n)
  {
    rep(j,i,n)
    {
      if (a[j]>a[i]) swap(a[i],a[j]);
    }
  }
}
void print(ll a[],ll n)
{
  rep(i,0,n) cout<<a[i]<<' ';
}
int main()
{
  ll a[]={5,8,2,7,6,4,1,1,9,9};
  ll n=10;
  ins_sort(a,n);
  print(a,n);
  return 0;
}