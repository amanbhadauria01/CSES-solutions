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
int dp[N][2][2][2];

/// 1 means pichhla lena hi hai , 0 means naya hi shuru karege

void go(){
   cin >> n ; 
   cout << dp[n][0][0][0] << endl;
} 

signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0] = 1;
        for(int i = 1 ; i < N ; i++){
            // l , r 
            for(int l = 0 ; l <= 1 ; l++){
                for(int r = 0 ; r <= 1 ; r++){
                    dp[i][l][r][0] += dp[i-1][1][1][0];
                    dp[i][l][r][0] += dp[i-1][0][1][0];
                    dp[i][l][r][0] += dp[i-1][1][0][0];
                    dp[i][l][r][0] += dp[i-1][0][0][0];
                    dp[i][l][r][0] %= MOD; 
                    dp[i][l][r][0] += MOD;
                    dp[i][l][r][0] %= MOD;
                }
            }
            dp[i][0][0][0] += dp[i-1][0][0][0] + dp[i-1][0][0][1];
            dp[i][0][0][0] %= MOD; dp[i][0][0][0] += MOD; dp[i][0][0][0] %= MOD;
            // b
            dp[i][0][0][1] = dp[i-1][0][0][1] + dp[i-1][0][0][0];
            dp[i][0][0][1] %= MOD; dp[i][0][0][1] += MOD; dp[i][0][0][1] %= MOD; 
        }
        cout << fixed << setprecision(12) ;
        cin >> t;
        while(t--){
            // cout << "Case #" << cases << ": ";
            go();
        }

}