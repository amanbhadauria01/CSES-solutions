#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// #define int long long 
// const int inf = 1e18;
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
int dp[N];
int coins[101];

//making mod const int made my code faster and pass the time limits

void go(){
    int x;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++)cin >> coins[i];
    dp[0] = 1;
    for(int i = 1 ; i <= x ; i++){
        dp[i] = 0;
        for(int j = 0 ; j < n ; j++){
            if(coins[j]<=i)dp[i] += dp[i-coins[j]];
            dp[i] %= MOD ;
        }
    }
    cout << dp[x] ;
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