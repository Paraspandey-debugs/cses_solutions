#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
good implementation + observation quesions ,
diagonal starts with 1 and difference is multiple of 2
so the number at ith position is , 
1 + 2 + 4 + .. 2*(i-1) , 1 + 2*(1 + 2 + 3 .. (i-1))
1 + (i*(i-1))

*/
void solve() {
    int y , x;
    cin>>y>>x;
    int k = max(y,x);
    int num = 1 + k*(k-1);
    int diff = abs(y-x);
    if(k%2 == 0){
        if(y > x){
            cout<<num + diff<<endl;
        }else{
            cout<<num - diff<<endl;
        }
    }else{
        if(y > x){
            cout<<num - diff<<endl;
        }else{
            cout<<num + diff<<endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
    cin>>t;
    while(t--){
        solve();
    }

	return 0;
}
