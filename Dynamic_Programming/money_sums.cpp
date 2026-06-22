#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int sum = 0;
    for(int i = 0 ; i < n ; i ++){
        cin>>v[i];
        sum += v[i];
    }
    vector<int>dp(sum,0);
    set<int>s;
    s.insert(0);
    for(int i = 0 ; i < n ; i ++){
        set<int>ps = s;
        for(const int& j : ps){
            if(s.find(j+v[i]) == s.end()){
                s.insert(j+v[i]);
            }
        }
    }
    cout<<s.size()-1<<endl;
    for(const int& i : s){
        if(i != 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}