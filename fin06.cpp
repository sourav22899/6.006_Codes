// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    longest common subsequence with subsequence printed...better algo for actually printing the subseq exists
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    char s[50],t[50];
    cin>>s>>t;
    ll m = strlen(s);
    ll n = strlen(t);
    ll lcs[m+1][n+1];
    rep(i,0,m+1)
    {
        rep(j,0,n+1)
        {
            if (i == 0 || j == 0) lcs[i][j] = 0;
            else if (s[i-1] == t[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else 
            {
                ll a = max(lcs[i][j-1],lcs[i-1][j]);
                lcs[i][j] = a;
            }
        }
    }
    rep(i,0,m+1)
    {
        rep(j,0,n+1)
        {
            cout<<lcs[i][j]<<' ';
        }
        cout<<'\n';
    }
    char com[50];
    ll k = 0;
    rep(i,0,m+1)
    {
        rep(j,1,n+1)
        {
            if(lcs[i][j] > lcs[i][j-1] && lcs[i][j] == k+1)
            {
                com[k] = s[i-1];
                k++;
            } 
        }
    }
    com[k] = '\0';
    cout<<com<<'\n';
    return 0;
}
