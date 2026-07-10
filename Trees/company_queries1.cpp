#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LOG_M 20
void dfs(vector<vector<int>>&up,vector<vector<int>>&adj,int u,int p){
    up[u][0] = p;
    for(int j = 1 ; j < LOG_M ; j++){
        if(up[u][j-1] != -1){
            up[u][j] = up[up[u][j-1]][j-1];
        }
    }
    for(auto& v : adj[u]){
        dfs(up,adj,v,u);
    }
}
#define debug cout<<"debug"<<endl;
int32_t main(){
    int n , q;
    cin>>n>>q;
    vector<vector<int>>adj(n);
    for(int i = 1 ; i < n ; i ++){
        int t;
        cin>>t;
        t--;
        adj[t].push_back(i);
    }
    vector<vector<int>>up(n,vector<int>(LOG_M,-1));
    //debug
    dfs(up,adj,0,-1);
    for(int i = 0 ; i < q ; i++){
        int x , l;
        cin>>x>>l;
        int curr = x-1;
        for(int j = 0 ; j < LOG_M ; j++){
            if((1LL<<j) & l && curr != -1){
                curr = up[curr][j];
            }
        }
        if(curr != -1)curr++;
        cout<<curr<<endl;
    }

    
}