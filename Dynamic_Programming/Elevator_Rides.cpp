#include <bits/stdc++.h>
using namespace std;

#define int long long 
bool check(vector<int>&a,int w , int x){
    //bitmask dp aahhhhhhhhhhhhhhh
    int n = a.size();
    vector<int>dp(x,0);
    dp[0] = a[0];
    for(int i = 1; i < n ; i ++){
        vector<int>next(x,0);
        for(int j = 0 ; j < min(x,i) ; j++){
            next[]
        }
    }
}
int32_t main(){
    int n , x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    int l = 1;
    int r = n;
    while(l <= r){
        int mid = (r-l)/2 + l;
        if(check(a,x,mid)){

        }
    }
}