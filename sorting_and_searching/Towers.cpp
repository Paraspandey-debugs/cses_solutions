#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    multiset<int>s;
    for(int i = 0 ; i < n ; i ++){
        auto it = s.upper_bound(a[i]);
        if(it != s.end()){
            s.erase(it);
        }
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
}