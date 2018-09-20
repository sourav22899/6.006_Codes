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
ll peak(ll a[],ll l,ll r)
{
  if(l<r)
  {
    ll mid = l+(r-l)/2;
    //cout<<mid<<endl;
    if(a[mid] < a[mid+1] && mid+1 <= r) return peak(a,mid+1,r);
    else if(a[mid] < a[mid-1] && mid >=l) return peak(a,l,mid-1);
    else return mid;
  }
}
int main()
{
  ll a[]={1,2,4,2,3,4,5,4,2,1};
  cout<<peak(a,0,9)<<endl;
  return 0;
}