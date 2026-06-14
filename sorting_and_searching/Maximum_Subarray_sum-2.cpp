#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n ,a , b;
    cin>>n>>a>>b;
    vector<int>v(n);
    for(int i = 0 ; i  < n ; i ++){
        cin>>v[i];
    }
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;
    vector<int>prefix(n+1,0);
    for(int i = 0 ; i < n ; i ++){
        prefix[i+1] = prefix[i] + v[i];
    }
    int ans = LLONG_MIN;
    for (int r = a; r <= n; r++) {
        pq.push({prefix[r-a], r-a});

        while (!pq.empty() && pq.top().second < r-b)
            pq.pop();

        ans = max(ans, prefix[r] - pq.top().first);
    }
    cout<<ans<<endl;

}