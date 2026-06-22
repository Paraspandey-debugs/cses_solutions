#include <bits/stdc++.h>
using namespace std;
#define int long long
void printlcs(vector<int>&a , vector<int>&b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max({dp[i-1][j] , dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
    int l = n;
    int r = m;
    vector<int>ans;
    while(l > 0 && r > 0){
        if(a[l-1] == b[r-1]){
            ans.push_back(a[l-1]);
            l--;
            r--;
            continue;
        }
        if(dp[l-1][r] > dp[l][r-1]){
            l--;
        }else{
            r--;
        }
    }
    reverse(ans.begin(),ans.end());
    
    for(int i = 0 ; i < ans.size(); i ++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int32_t main(){
    int n , m ;
    cin>>n>>m;
    vector<int>a(n);
    for(int i = 0 ; i  < n ; i ++){
        cin>>a[i];
    }
    vector<int>b(m);
    for(int i = 0 ; i  < m ; i ++){
        cin>>b[i];
    }
    printlcs(a,b);
}