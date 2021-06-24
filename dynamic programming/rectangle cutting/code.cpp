#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 1e6 + 10;
int n , m; 
int dp[501][501];

int rec(int i , int j){
    if(i==j)return 0;
    if(i==0 || j==0)return inf;
    int & ans = dp[i][j];
    if(ans != -1)return ans;
    ans = inf;
    for(int k = 1 ; k < j ; k++){
        ans = min(ans,rec(i,k)+rec(i,j-k)+1);
    }
    for(int k = 1 ; k < i ; k++){
        ans = min(ans,rec(k,j)+rec(i-k,j)+1);
    }
    return ans;
}

void go(){
    cin >> n >> m ;
    memset(dp,-1,sizeof(dp));
    cout << rec(n,m);
} 

signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        while(t--){
            // cout << "Case #" << cases << ": ";
            go();
        }

}