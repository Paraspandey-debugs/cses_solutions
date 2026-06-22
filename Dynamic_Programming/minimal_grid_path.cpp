#include <bits/stdc++.h>
//unsolved
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>prev(n,vector<pair<int,int>(n,{-1,-1}));
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j <  n ; j ++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[n-1][n-1] = 0;
    for(int i = n-2 ; i >= 0 ; i--){
        dp[n-1][i] = 0;
        dp[i][n-1] = 1;
    }
    for(int i = n-2; i >= 0 ; i--){
        for(int j = n-2; j >= 0 ; j--){
            int l = i+1;
            int r = j;
            int x = i;
            int y = j+1;
            while(max({l,r,x,y}) < n && grid[l][r] == grid[x][y] ){
                if(dp[l][r] == 0){
                    r++;
                }else{
                    l++;
                }
                if(dp[x][y] == 0){
                    y++;
                }else{
                    x++;
                }
            }
            if(max({l,r,x,y}) < n){
                if(grid[l][r] > grid[x][y]){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1;
                }
            }
            
        }
    }
    string ans = "";
    int l = 0;
    int r = 0;
    while(l < n && r < n){
        ans += grid[l][r];
        if(dp[l][r] == 0){
            r++;
        }else{
            l++;
        }
    }
    cout<<ans<<endl;

}