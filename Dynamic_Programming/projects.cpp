#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>p(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i]>>b[i]>>p[i];
    }
    vector<vector<int>>vp;
    for(int i = 0 ; i < n ; i ++){
        vp.push_back({a[i],b[i],p[i]});
    }
    sort(vp.begin(),vp.end(),[&](const vector<int>&a,const vector<int>&b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });
    // for(int i = 0 ; i < n ; i ++){
    //     cout<<vp[i][0]<<" "<<vp[i][1]<<" "<<vp[i][2]<<endl;
    // }   
    vector<int>dp(n,0);
    vector<int>leftmax(n,0);
    dp[0] = vp[0][2];
    leftmax[0] = vp[0][2];
    for(int i = 1 ; i < n ; i ++){
        int l = 0;
        int r = i-1;
        int idx = 0;
        dp[i] = vp[i][2];
        while(l <= r){
            int mid = (r-l)/2 + l;
            if(vp[mid][1] >= vp[i][0]){
                r = mid-1;
            }else{
                l = mid+1;
                idx = mid;
            }
        }
        //cout<<"DEbug"<<idx<<endl;
        if(vp[idx][1] < vp[i][0]){
            dp[i] = max(dp[i],leftmax[idx] + vp[i][2]);
        }
        leftmax[i] = max(leftmax[i-1],dp[i]);
    }
    // for(int i = 0 ; i < n ; i ++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<*max_element(dp.begin(),dp.end());

}