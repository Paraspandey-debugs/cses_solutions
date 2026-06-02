#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
    observation
*/
void solve() {
    int n;
    cin>>n;
    if(n == 2 || n == 3){
        cout<<"NO SOLUTION\n";
        return;
    }
    int temp = n - (1 - n%2);
    while(temp > 0){
        cout<<temp<<" ";
        temp -=2;
    }
    n = (n/2)*2;
    while(n){
        cout<<n<<" ";
        n -= 2;
    }
    cout<<endl;
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}