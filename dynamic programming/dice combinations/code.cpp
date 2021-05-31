#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1e9 + 7;
#define fi first
#define se second
#define endl '\n'
const int N = 2e6 + 10;
int n ;
int dp[N];

void solve(){
    cin >> n ;
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= 6 ; j++){
            if(i-j>=0)dp[i] += dp[i-j];
            dp[i] %= MOD; dp[i] += MOD; dp[i] %= MOD;
        }
        dp[i] %= MOD; dp[i] += MOD; dp[i] %= MOD;
    }
    cout << dp[n] << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}