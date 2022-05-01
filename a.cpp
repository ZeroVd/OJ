#include<bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x){
    return x&-x;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int k; cin>>k;
    // cout<<k-1<<endl;
    int s=lowbit(k);
    if(k==lowbit(k)) s--;
    int cnt_s=0;
    int res=k-s;
    while(s){
        cnt_s++;
        s>>=1;
    }

    int n=res+cnt_s;
    
    for(int i=2;i<=res;i++){
        cout<<i<<' '<<i-1<<endl;
    }
    int tt=res;
    while(cnt_s--){
        cout<<res<<' '<<++tt<<endl;
    }
    


    // for(int i=2;i<=k-1;i++){
    //     cout<<i-1<<' '<<i<<endl;
    // }

    return 0;
}
