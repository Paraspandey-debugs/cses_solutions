#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
/*
    greedy picking , only work if numbers are in range 1 to n 
*/
void solve() {
	int n;
	cin>>n;
	int tot = (n*(n+1))/2;
	if(tot%2){
		cout<<"NO\n";
		return;
	}
	int x = tot/2;
	vector<int>a;
	vector<int>b;
	for(int i = n ; i>= 1 ; i--){
		if(x >=i ){
			x -= i;
			a.push_back(i);
		}else{
			b.push_back(i);
		}
	}
	cout<<"YES\n";
	cout<<a.size()<<endl;
	for(int i : a){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<b.size()<<endl;
	for(int i : b){
		cout<<i<<" ";
	}
	cout<<endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
