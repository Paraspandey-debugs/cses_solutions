#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+  7;

int binpow(int a , int n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    int temp = binpow(a,n/2);
    if(n%2 == 0){
        return (temp%mod*temp%mod)%mod;
    }else{
        return (a%mod*temp%mod*temp%mod)%mod;
    }
}
int32_t main(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    if(sum%2 != 0){
        cout<<0<<endl;
        return 0;
    }
    int target = sum/2;
    vector<int>dp(target+1,0);
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i ++){
        vector<int>prev = dp;
        for(int j = 0 ; j+ i <= target ; j++){
            if(prev[j] != 0){
                dp[j+i] = (dp[j+i] +prev[j])%mod;
            }
        }
    }
    cout<<(dp[target]%mod*binpow(2,mod-2))%mod<<endl;
}