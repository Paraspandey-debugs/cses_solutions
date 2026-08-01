#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
//optimize this shee
int32_t main() {
    // your code goes here
    int n ,k;
    cin>>n >>k;
    queue<int>q;
    for(int i = 1 ; i <= n ; i ++){
        q.push(i);
    }
    while(!q.empty()){
        int t = k%q.size();
        while(t--){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    
}