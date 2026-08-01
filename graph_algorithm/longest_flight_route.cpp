#include <bits/stdc++.h>
using namespace std;

int main() {
	int n , m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>indeg(n+1,0);
    vector<int>parent(n+1,0);
    for(int i = 0 ; i < m ; i ++){
        int a , b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    vector<int>dp(n+1,0);
    dp[1] = 1;
    queue<int>q;

    for(int i = 1 ; i <= n ; i ++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto& v : adj[x]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
            if( dp[x] != 0 && dp[x] + 1 > dp[v]){
                dp[v] = dp[x] + 1;
                parent[v] = x;
            }
        }
    }
    if(dp[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int curr = n;
    vector<int>ans;
    while(curr != 1){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);
    
    cout<<dp[n]<<endl;
    for(int i = dp[n]-1;i >= 0 ; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
