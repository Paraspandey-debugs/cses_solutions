#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    const int mod = 1e9+7;
    int  n , x;
    cin>>n>>x;
    vector<int>w(n);
    vector<int>v(n);
    for(int i = 0 ; i < n  ; i ++){
        cin>>w[i];
    }
    for(int i = 0 ; i < n ; i ++){
        cin>>v[i];
    }
    vector<int>dp(x+1,0);
    for(int i = 0 ; i < n  ; i ++){
        for(int j = x;  j >= w[i] ; j--){
            dp[j] = max(dp[j] , dp[j - w[i]] + v[i]);
        }
    }
    cout<<dp[x]<<endl;
}