#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
#define eps 1e-7

const int N=505,mod=1e9+7;

int n,m;
double P;

bool check(double mid){
    return 0.5*sqrt(mid*mid*mid)+sin(mid)>P;
}

void slove()
{
    
    cin >> P;
    double l=0.0, r=1e12;
    while(r-l>eps){
        double mid = (r+l)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout << l << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) slove();
    return 0;
}