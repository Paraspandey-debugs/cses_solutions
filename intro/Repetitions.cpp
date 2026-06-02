#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
    why am i even solving  such questions  ??
*/
void solve() {
    string s;
    cin>>s;
    int c = 0;
    char curr = s[0];
    int ans = 0;
    for(int i = 0 ; i < s.size(); i ++){
        if(s[i] == curr){
            c++;
        }else{
            ans = max(ans,c);
            c = 1;
            curr = s[i];
        }
    }
    cout<<max(ans,c)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}