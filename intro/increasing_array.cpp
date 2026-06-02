#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
    just greedy, while solving i thought goving backwards is good ,
    but when writing case 7 3 2 1 came in mind so ya from front to back
*/
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 1; i < n ; i++){
        if(a[i] < a[i-1]){
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout<<ans<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}