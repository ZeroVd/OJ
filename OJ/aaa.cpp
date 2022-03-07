#include <iostream>
#include <queue>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define ll long long    
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define N 2005
#define maxn 10
const ll mod = 1e9+7;

int n,k,g[maxn][maxn];
int sty[maxn];
ll ans;

void dfs(int p, int x){
    if(p==k){ 
        ans++;
        return; 
    }
    for(int i=x; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!sty[j] && !g[i][j]){
                sty[j]=1;
                dfs(p+1, i+1);
                sty[j]=0;
            }
        }
    }
}

int main()
{
    char ch;
    while(cin >> n >> k && n!=-1 && k!=-1){
        ans=0;
        for(int i=0; i<maxn; i++) sty[i]=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                cin >> ch;
                if(ch=='.') g[i][j]=1;
                else g[i][j]=0;
            }
        dfs(0, 1);
        cout << ans << endl;
    }
    return 0;
}

/*
4 4
.###
#.##
##.#
###.

4 4
...#
..#.
.#..
#...

*/