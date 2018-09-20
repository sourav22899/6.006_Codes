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
ll parent(ll i)
{
  return (i-1)/2;
}
ll right(ll i)
{
  return 2*i+2;
}
ll left(ll i)
{
  return 2*i+1;
}
void maxHeapify(ll a[],ll n,ll i)
{
  ll l = left(i);
  ll r = right(i);
  ll largest = 0;
  if(a[l] > a[i] && l < n) largest = l;
  else largest = i;
  if(a[r] > a[largest] && r < n) largest = r;
  if(largest != i) 
  {
    swap(a[i],a[largest]);
    maxHeapify(a,n,largest);
  }
}
void buildMaxHeap(ll a[],ll n)
{
  for(ll i = (n/2)-1; i > -1 ; i--) maxHeapify(a,n,i);
}
void heapsort(ll a[],ll n)
{
  buildMaxHeap(a,n);
  for(ll i = n-1;i > 0;--i)
  {
    swap(a[0],a[i]);
    maxHeapify(a,i,0);
  }
}
int main()
{
  ll a[] = {8,6,9,2,3,1,5};
  heapsort(a,7);
  rep(i,0,7) cout<<a[i]<<' ';
  return 0;
}
