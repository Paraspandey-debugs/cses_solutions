#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    vector<int>dp;
    for(int i = 0 ; i < n ; i ++){
        auto it = lower_bound(dp.begin(),dp.end(),a[i]);
        if(it == dp.end()){
            dp.push_back(a[i]);
        }else{
            int idx = it - dp.begin();
            dp[idx] = a[i];
        }
    }
    cout<<dp.size()<<endl;
}