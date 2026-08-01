#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int foo(vector<vector<int>>&dp,int a, int b){
    int n = dp.size()-1;
    int m = dp[0].size()-1;
    if(a > n || b > m){
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    int ways = 0;
    if(a >= 2){
        ways = (ways%mod + dp[a-2][b]%mod + dp[2][b]%mod)%mod;
    }
    if(b >= 2){
        ways = (ways%mod + dp[a][b-2]%mod + dp[a][2]%mod)%mod;
    }
    return dp[a][b] = ways;
}
int32_t main() {
	// your code goes here
    int n , m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    if(n >=2){
        dp[2][1] = 1;
    }
    if(m >= 2){
        dp[1][2] = 1;
    }
    foo(dp,n,m);
    cout<<dp[n][m]<<endl;
}
