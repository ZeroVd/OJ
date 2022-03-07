#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define LL long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f
#define N 1005
#define maxn 300005
const LL mod = 1e9+7;

int n,l,r,ans;
unordered_set<string> S;
int cnt[4],len,f[N];

int main()
{
    IOS;
    string str;
    cin >> n >> l >> r;
    cin >> str;
    for(int i=0,j=0; i<str.size(); i++){
        if(str[i]>='a'&&str[i]<='z'){
            len++;
            cnt[0]++;
            f[i]=0;
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            len++;
            cnt[1]++;
            f[i]=1;
        }
        else if(str[i]>='0'&&str[i]<='9'){
            len++;
            cnt[2]++;
            f[i]=2;
        }
        else{
            len++;
            cnt[3]++;  
            f[i]=3; 
        }
        if(len>r){
            len--;
            cnt[f[j]]--;
            j++;
        }
        if(len>=l && len<=r){
            string t = str.substr(j, len);
            if(cnt[0]>0 && cnt[1]>0 && cnt[2]>0 && cnt[3]>0 && !S.count(t)){
                S.insert(t);
                ans++;
            }
        }
    }

    return 0;
}