#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n , x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    vector<int>dp(x+1,1e10);
    dp[0] = 0;
    for(int i = 1 ; i < x+1 ; i ++){
        for(int j = 0 ; j < n ; j++){
            if(a[j] <= i && dp[i-a[j] != 1e10]){
                dp[i] = min(dp[i],1+ dp[i- a[j]]);
            }
        }
    }
    if(dp[x] == 1e10){
        cout<<-1<<endl;
        return 0 ;
    }
    cout<<dp[x]<<endl;

    
}