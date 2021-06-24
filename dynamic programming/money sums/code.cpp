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
const int N = 1e5 + 10;
int n , m; 
bool dp[101][N];
int a[101];

void go(){
    cin >> n  ;
    int w = 0;
    for(int i = 0 ; i < n ; i++)cin >> a[i] , w += a[i];
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i <= n ; i++)dp[i][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= w ; j++){
            if(a[i-1]<=j)dp[i][j] |= dp[i-1][j-a[i-1]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    vector<int> v;
    for(int i = 1 ; i <= w ; i++)if(dp[n][i])v.push_back(i);
    cout << v.size() << endl;
    for(auto x : v)cout << x << " "; 
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