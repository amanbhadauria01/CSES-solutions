#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
 
void go(){
  int n ; cin >> n ; 
  int b = 1;
  for(int i = 0 ; i < n ; i++){
      b *= 2;
      b %= MOD; b += MOD; b %= MOD;
  }
  cout << b << endl;
} 
 
signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        int cases = 1;
        while(t--){
            // cout << "Case #" << cases << ": "; cases++;
            go();
        }
 
}