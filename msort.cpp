#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a>=b?a:b
#define min(a,b) a>=b?b:a
#define F first
#define S second
////////merge sort/////////
void merge(ll a[],ll l,ll m,ll r)
{
  ll n1 = m-l+1;
  ll m1 = r-m;
  ll k = l;
  ll L[n1],R[m1];
  rep(i,0,n1) L[i] = a[i+l];
  rep(j,0,m1) R[j] = a[m+1+j];
  ll i = 0,j = 0;
  while(i<n1 && j<m1)
  {
    if(L[i] <= R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
    {
      a[k]=R[j];
      j++;
    }
    k++;
  }
  while(j < m1)
  {
    a[k]=R[j];
    k++;j++;
  }
  while(i < n1)
  {
    a[k]=L[i];
    k++;i++;
  }
}
void msort(ll a[],ll l,ll r)
{
  if(l < r)
  {
    ll m = (l+r)/2;
    msort(a,l,m);
    msort(a,m+1,r);
    merge(a,l,m,r);
  }
  //cout<<'X'<<endl;
}
int main()
{
  ll a[6]={4,8,2,3,6,1};
  msort(a,0,5);
  rep(i,0,6) cout<<a[i]<<' ';
  return 0;
}
