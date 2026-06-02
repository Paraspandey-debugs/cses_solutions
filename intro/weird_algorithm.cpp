#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
// implementation only no need to revise
void solve() {
    int n;
    cin>>n;
    while(n != 1){
        cout<<n<<" ";
        if(n%2 == 0){
            n /= 2;
        }else{
            n *= 3;
            n++;
        }
    }
    cout<<1<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}