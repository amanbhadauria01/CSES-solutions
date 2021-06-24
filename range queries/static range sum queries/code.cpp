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
const int N = 2e5 + 10;
int n  , q , a[N] , pre[N] ;

void go(){
    cin >> n >> q ; 
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    pre[0] = a[0];
    for(int i = 1 ; i < n ; i++)pre[i] = pre[i-1] + a[i];
    for(int i = 1 ; i <= q ; i++){
         int a , b ; cin >> a >> b ; 
         a-- ; b-- ;
         int ans = pre[b];
         if(a>0)ans -= pre[a-1];
         cout << ans << endl; 
    }
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