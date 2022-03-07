#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
const int N=10,INF=0x3f3f3f3f;
int res;
int g[N][N];
bool st[N][N];
int k;

void dfs(int x, int y, int ans, int n){
    cout << x << ' ' << y << endl;
    res = max(res, ans);
    if(res == 17) return;
    // cout << k++ << endl; 
    for(int k=0; k<4; k++){
        int a=x+dx[k],b=y+dy[k];
        if(a<1 || a>5 || b<1 || b>5 || st[a][b]) continue;
        if(g[a][b]>=INF/2) continue;
        double t=g[a][b];
        t = ceil(t/6);
        if(n>=t){
            st[a][b] = true;
            dfs(a,b,ans+1,n-t);
            st[a][b] = false;
        }
    }
}

void slove(){
    res = 0;
    memset(g, 0x3f, sizeof g);
    memset(st, 0, sizeof st);
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++){
            if(j==1 && (i==2 || i==3 || i==4)) continue;
            if(j==5 && (i==2 || i==3 || i==4)) continue;
            if(j==3 && (i==1 || i==5)) continue;
            cin >> g[i][j];
        }
    int n;
    cin >> n;

    dfs(5,0,0,n);

    cout << res << endl;
}

int main()
{
    int t=1;
    cin >> t;
    while(t--) slove();
    return 0;
}