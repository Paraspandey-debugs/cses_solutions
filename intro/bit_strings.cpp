#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int mod  = 1e9+7;
int bin_pow(int a , int n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return a;
	}
	if(n%2 == 0){
		int temp = bin_pow(a,n/2);
		return (temp%mod*temp%mod)%mod;
	}
	int temp = bin_pow(a,n/2);
	return (a%mod*temp%mod*temp%mod)%mod;
}
void solve() {
	int n;
	cin>>n;
	cout<<bin_pow(2,n)<<endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
