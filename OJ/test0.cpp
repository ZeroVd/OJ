#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define LL long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define N 1000005
#define maxn 6005
const LL mod = 1e9+7;
#define lowbit(x) x&-x

int n;
LL ans;
priority_queue<LL, vector<LL>, greater<LL>> q;

int main()
{
    cin >> n; 
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        q.push(x);
    }

    for(int i=1; i<n; i++){
        LL t=q.top(); q.pop();
        t += q.top(); q.pop();
        q.push(t);
        ans += t;
    }
    cout << ans;
    return 0;
}