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
void print(ll n,ll m,ll a[][m])
{
  rep(i,0,n)
  {
    rep(j,0,m) cout<<a[i][j]<<endl;
  }
}
int main()
{
  ll a[3][3]={{4,8,2},{6,5,6},{1,7,5}};  
  print(3,3,a);
  return 0;
}