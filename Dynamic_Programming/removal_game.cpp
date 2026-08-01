#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	// your code goes here
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,LLONG_MIN));
    for(int l = 1 ; l <= n ; l++){
        for(int i = 0 ; i <= n - l ; i++){
            int j = i + l -1 ;
            int A = 0;
            if(i+1 < n && j-1 >= 0 && i+1 <= j-1){
                A = dp[i+1][j-1];
            }
            int b = 0;
            if(i+2 < n && i+2 <= j){
                b = dp[i+2][j];
            }
            int c = 0;
            if(j-2 >= 0 && i <= j-2){
                c = dp[i][j-2];
            }
            dp[i][j] = max(dp[i][j] , a[i] + min(A , b));
            dp[i][j] = max(dp[i][j] , a[j] + min(A,c));
        }
    }
    cout<<dp[0][n-1]<<endl;
}
