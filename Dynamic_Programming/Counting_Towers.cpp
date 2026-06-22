#include <bits/stdc++.h>

using namespace std;
#define int long long
//retry : unsolved
const int mod = 1e9 +7;
vector<int>dp(1e6+1,0);
void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
}
void init(){
    vector<int>prefix(1e6+1,0);
    vector<int>dp1(1e6+1,0);
    vector<int>prefix1(1e6+1,0);
    for(int i = 1; i <= 1e6 ; i++){
        dp1[i] = (1 + prefix1[i-1])%mod;
        prefix1[i] = (prefix1[i-1] + dp1[i])%mod;
    }
    for(int i = 1 ; i <= 1e6 ; i ++){
        dp[i] = 1;
        
    }
}
int32_t main(){
    init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}