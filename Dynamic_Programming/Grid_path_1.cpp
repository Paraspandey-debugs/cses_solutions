#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    const int mod = 1e9+7;
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    if(grid[0][0] == '*'){
        cout<<0<<endl;
        return 0 ;
    }
    dp[0][0] = 1;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            if((i == 0 && j == 0) || grid[i][j] == '*')continue;
            if(i > 0 && grid[i-1][j] != '*' ){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            }
            if(j > 0 && grid[i][j-1] != '*'){
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    // for(int i = 0 ; i  < n ; i ++){
    //     for(int j = 0 ; j  < n ; j ++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][n-1]<<endl;
}