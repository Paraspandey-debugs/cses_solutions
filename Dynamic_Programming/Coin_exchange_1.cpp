#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    const int mod = 1e9 + 7;
    int n , x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    vector<int>dp(x+1,0);
    dp[0] = 1;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 1 ; j  < x+1 ; j++){
            if(j >= a[i]){
                dp[j] = (dp[j - a[i]] + d[j])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;

    
}