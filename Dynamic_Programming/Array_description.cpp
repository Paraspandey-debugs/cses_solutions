#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    const int mod = 1e9+7;
    int  n , m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    vector<int>dp(m+1,0);
    if(a[0] == 0){
        for(int i = 1 ; i <= m ; i ++){
            dp[i] = 1;
        }
    }else{
        dp[a[0]] = 1;
    }
    for(int i = 1 ; i <  n ; i++){
        vector<int>next(m+1,0);
        if(a[i] != 0){
            next[a[i]] = dp[a[i]];
            if(a[i]-1 > 0){
                next[a[i]] = (next[a[i]]+ dp[a[i]-1])%mod;
            }
            if(a[i] + 1 <=m){
                next[a[i]] = (next[a[i]] + dp[a[i]+1])%mod;
            }
        }else{
            for(int j = 1;  j <= m ; j ++){
                if(j+1 <= m){
                    next[j] = dp[j+1];
                }
                next[j] = (next[j] + dp[j-1] + dp[j])%mod;
            }
        }
    
        dp = next;
    }
    int ans = 0;
    for(int i =  1; i <= m ; i ++){
        ans = (ans + dp[i])%mod;
    }
    cout<<ans<<endl;

}