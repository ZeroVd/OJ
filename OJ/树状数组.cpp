#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define maxn 100005
const ll mod = 1e9+7;

#define lowbit(x) x&(-x)
int tree[maxn], n;
//单点更新，区间求和
void update(int p, int v){          //单点更新
    for(int i=p; i<=n; i+=lowbit(i)) tree[i]+=v;
}
int getsum(int p){                  //区间求和
    int res=0;
    for(int i=p; i; i-=lowbit(i)) res+=tree[i];
    return res;
}

//区间更新，区间查询
void add(ll *r, int p, int v){          //单点更新
    for(int i=p; i<=n; i+=lowbit(i)) r[i]+=v;
}
int Gsum(ll *r, int p){                  //区间求和
    int res=0;
    for(int i=p; i; i-=lowbit(i)) res+=r[i];
    return res;
}
void rangeUpdate(){
    memset(tree, 0, sizeof tree);
    int a[maxn] = {0};
    ll delta[maxn] = {0}, deltai[maxn] = {0};
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    int q, t1, t2; cin >> q;
    while(q--){
        int op; cin >> op >> t1 >> t2;
        if(op==1){
            int c; cin >> c;
            add(delta, t1, c); add(delta, t2+1, -c);
            add(deltai, t1, t1*c); add(deltai, t2+1, -(t2+1)*c); 
        }
        else {
            int sum1 = a[t1-1] + t1*Gsum(delta, t1-1) - Gsum(deltai, t1-1);
            int sum2 = a[t2] + (t2+1)*Gsum(delta, t2) - Gsum(deltai, t2);
            cout << sum2-sum1 << endl;
        }
    }
}

//求逆序对
int calcReverse(){    
    memset(tree, 0, sizeof tree);     
    pii a[maxn];
    int b[maxn] = {0};
    //离散化
    cin >> n;
    for(int i=1; i<=n; i++) {cin >> a[i].first; a[i].second=i;}
    sort(a+1, a+n+1);       //
    for(int i=1; i<=n; i++) b[a[i].second] = i;
    //计算逆序对
    ll res = 0;
    for(int i=1; i<=n; i++){
        update(b[i], 1);
        res += i-getsum(b[i]);
    }
    return res;
}



//求区间最值
int rangeMax(){
    memset(tree, 0, sizeof tree);
    
    return 0;
}


int main()
{
    cout << calcReverse();

    return 0;
}