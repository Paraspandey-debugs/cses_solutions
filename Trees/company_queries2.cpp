#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LOG_M 20
void dfs(vector<vector<int>>&adj,vector<vector<int>>&up,vector<int>&depth,int u,int p){
    depth[u] = depth[p] + 1;
    if(p != 0){
        up[u][0] = p;
    }
    else{
        up[u][0] = u;
    }
    for(int j = 1 ; j < LOG_M ; j++){
        up[u][j] = up[up[u][j-1]][j-1];
    }
    for(auto& v : adj[u]){
        dfs(adj,up,depth,v,u);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1);
    vector<int>depth(n+1,0);
    depth[0] = -1;
    for(int i = 2 ; i <= n ; i ++){
        int t;
        cin>>t;
        adj[t].push_back(i);
    }
    vector<vector<int>>up(n+1,vector<int>(LOG_M,0)); 
    dfs(adj,up,depth,1,0);
    for(int i = 0 ; i < q ; i ++){
        int l , r;
        cin>>l>>r;
        if(depth[l] < depth[r]){
            swap(l,r);
        }
        int k = depth[l] - depth[r];
        for(int j = 0 ; j < LOG_M ; j++){
            if((1LL<<j)&k){
                l = up[l][j];
            }
        }
        for(int j = LOG_M-1 ; j >= 0 ; j--){
            if(up[l][j] != up[r][j]){
                l = up[l][j];
                r = up[r][j];
            }
        }
        while(l != r){
            l = up[l][0];
            r = up[r][0];
        }
        
    
        cout<<l<<"\n";
    }


}