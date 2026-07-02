#include <bits/stdc++.h>
using namespace std;
#define int long long

// a c d e b
// asume d is largest ,
// i can visit both sides from d 
// so my ans wouldbe maxof 1 + max(foo(2 ,  end),foo(0,1))
// i want range index max without updation
//repetation of subproblem ?
// nlog(n)?

int32_t main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i ++){
        cin>>a[i];
    }

}