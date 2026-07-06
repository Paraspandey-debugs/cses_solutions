#include <bits/stdc++.h>
//think
using namespace std;

int32_t main(){
    int n , k;
    cin>>n>>k;
    int x , a , b , c;
    cin>>x>>a>>b>>c;
    int bit[32] = {0};
    queue<int>q;
    int curr = x;
    int curr_or = 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i ++){
        if(q.size() < k ){
            for(int j = 0 ; j < 32 ;j ++){
                if((1<<j) & curr){
                    bit[j]++;   
                }
            }
            
        }else{
            int temp = q.front();
            q.pop();
            for(int j = 0 ;j < 32 ; j ++){
                if((1<<j) & temp){
                    bit[j]--;
                    if(bit[j] == 0){
                        curr_or ^= (1<<j);
                    }
                }
                if((1<<j)&curr){
                    bit[j]++;
                }
                
            }
        }
        curr_or |= curr;
        q.push(curr);
        curr = (1LL*a*curr + b)%c;
        
        if(q.size() == k){
            //cout<<curr_or<<endl;
            ans ^= curr_or;
        }
    }
    cout<<ans<<endl;
}