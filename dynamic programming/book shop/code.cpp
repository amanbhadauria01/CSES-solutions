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
int n , x ;
int cost[1001],value[1001];
int dp[2][N];

void go(){
   cin >> n >> x;
   for(int i = 0 ; i < n ; i++)cin >> cost[i];
   for(int i = 0 ; i < n ; i++)cin >> value[i];
   for(int j = 0 ; j <= x ; j++)dp[0][j] = 0;
   dp[1][0] = 0;
   dp[0][0] = 0;
   for(int i = 1 ; i <= n ; i++)
     for(int j = 1 ; j <= x ; j++){
         dp[i%2][j] = 0;
         if(cost[i-1] <= j)dp[i%2][j] = dp[((i-1)%2 + 2)%2][j-cost[i-1]] + value[i-1];
         dp[i%2][j] = max(dp[i%2][j],dp[((i-1)%2 + 2)%2][j]);
     }
   cout << dp[n%2][x] ;  
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