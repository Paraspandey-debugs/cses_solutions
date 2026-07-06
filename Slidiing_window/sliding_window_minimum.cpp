#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n , k;
    cin>>n>>k;
    int x , a , b , c;
    cin>>x>>a>>b>>c;
    deque<pair<int,int>>minq;
    int ans = 0;
    int curr = x;
    
    for(int i = 0 ; i < n ; i ++){
        while(!minq.empty() && ( (i - minq.front().second ) >= k))minq.pop_front();
        while(!minq.empty() && ( minq.back().first > curr))minq.pop_back();
        
        minq.push_back({curr,i});
        if(i - k + 1 >= 0){
            //cout<<minq.front().first<<endl;
            ans ^= minq.front().first;
        }
        curr = (a*curr + b)%c;

    }
    cout<<ans<<endl;
}