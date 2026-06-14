#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

long long getTot(long long curr, long long n) {
    long long tot = 0;
    long long sig = 1;
    long long coef = 1;

    while (curr <= n) {
        tot += coef * sig * (n / curr);
        curr *= 2;
        sig *= -1;
        coef++;
    }

    return tot;
}
void solve() {
	int n;
	cin>>n;
	int tot_2 = getTot(2,n);
	int tot_5 = getTot(5,n);
	int tot_10 = getTot(10,n);
	cout<<min(tot_2 - tot_10 , tot_5 - tot_10) + tot_10<<endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
