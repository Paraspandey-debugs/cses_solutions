#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
//wont work , nieve
int32_t main() {
    // your code goes here
    int n , x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    int ans = 0;

    vector<int>prefix(n+1,0);
    map<int,int>hash;
    for(int i = 0 ; i < n ; i ++){
        prefix[i+1] = prefix[i] + a[i];
        
    }
    for(int i = n ; i >= 0 ; i --){
        if(hash.count(prefix[i] + x)){
            ans += hash[prefix[i] + x];
        }
        hash[prefix[i]]++;
    }
    
    cout<<ans<<endl;
    
}