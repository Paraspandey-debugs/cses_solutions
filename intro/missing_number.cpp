#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
All numbers are distinct. Compute the XOR of 1..n, then XOR it with
every value in the input array. Since a ^ a = 0, the remaining value
is the missing number.
*/
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    int xor_val = 0;
    for(int i = 0 ; i < n ; i ++){
        xor_val ^= i+1;
    }
    for(int i = 0 ; i < n-1 ; i++){
        cin>>a[i];
        xor_val ^= a[i];
    }
    cout<<xor_val<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}