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
int n; 
int dp[2][N];
int a[501];

int power(int a, int b){
   if(b==0)return 1;
   int temp = power(a,b/2);
   temp *= temp;
   temp %= MOD ; temp += MOD; temp %= MOD;
   if(b%2)temp *= a;
   temp %= MOD ; temp += MOD; temp %= MOD;
   return temp;
}

void go(){
    cin >> n ;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)a[i] = i+1 , sum += a[i];
    if(sum%2){
        cout << 0 << endl; return ;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= sum ; j++){
            dp[i%2][j] = 0;
            if(a[i-1]<=j)dp[i%2][j] += dp[((i-1)%2 + 2)%2][j-a[i-1]];
            dp[i%2][j] += dp[((i-1)%2 + 2)%2][j]; 
            dp[i%2][j] %= MOD; dp[i%2][j] += MOD; dp[i%2][j] %= MOD;
        }
    } 
    int inv2 = power(2,MOD-2);
    cout << ((((dp[n%2][sum/2])*inv2)%MOD + MOD )%MOD) << endl;
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