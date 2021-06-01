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
int n ;
int dp[1001][1001];
vector<string> a;

void go(){
   cin >> n ;
   a.resize(n);
   for(int i = 0 ;i < n ; i++)cin >> a[i];
   dp[0][0] = (a[0][0]!='*');
   for(int i = 1 ;i < n ; i++)dp[i][0] = (a[i][0]!='*')*(dp[i-1][0]);
   for(int j = 1 ;j < n ; j++)dp[0][j] = (a[0][j]!='*')*(dp[0][j-1]);
   for(int i = 1 ;i < n ; i++){
       for(int j = 1 ; j < n ; j++){
           dp[i][j] = (a[i][j]!='*')*(dp[i-1][j] + dp[i][j-1]);
           dp[i][j] %= MOD; dp[i][j] += MOD; dp[i][j] %= MOD;
       }
   }
   cout << dp[n-1][n-1];
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