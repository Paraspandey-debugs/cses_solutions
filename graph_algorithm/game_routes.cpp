#include <bits/stdc++.h>
using namespace std;

int main() {
	int n , m;
	cin>>n>>m;
	const int mod = 1e9 + 7;
	vector<vector<int>>adj(n+1);
	vector<int>indeg(n+1,0);
	for(int i = 0 ; i < m ; i++){
	    int x , y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    indeg[y]++;
	}
	vector<int>dp(n+1,0);
	dp[1] = 1;
	
	queue<int>q;
    for(int i = 1 ; i <= n ; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto& v : adj[x]){
            dp[v] = (dp[v] +  dp[x])%mod;
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    cout<<dp[n]<<endl;
}
