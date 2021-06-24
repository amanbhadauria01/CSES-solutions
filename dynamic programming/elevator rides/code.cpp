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
int n,x,a[22];
pair<int,int> dp[1<<21];

void go(){
    cin >> n >> x; 
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    dp[0] = {1,0};
    for(int i = 1 ; i < (1<<n) ; i++){
        dp[i] = {n+1,0};
        for(int j = 0 ; j < n ; j++){
            if((i>>j)&1){
                auto p = dp[i^(1<<j)];
                if(p.se + a[j] <= x){
                    p.se += a[j];
                }else{
                    p.fi++;
                    p.se = a[j];
                }
                dp[i] = min(dp[i],p);
            }
        }
    }
    cout << dp[(1<<n)-1].fi << endl;
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