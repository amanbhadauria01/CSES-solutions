#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
// const int inf = 1e18;
// #define D long double
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
const int N = 2e5 + 10;
int n , q ;
const int LOGN = 32;
int jmp[N][LOGN];

void go(){
  cin >> n >> q ; 
  for(int i = 1 ; i <= n ; i++){
      cin >> jmp[i][0];
  }
  for(int j = 1 ; j < LOGN ; j++){
      for(int i = 1 ; i <= n ; i++){
          jmp[i][j] = jmp[jmp[i][j-1]][j-1];
      } 
  }
  while(q--){
      int x, k ; cin >> x >> k ;
      for(int j = LOGN-1 ; j >= 0 ; j--){
          if((1LL<<j)<=k){
              x = jmp[x][j];
              k -= (1<<j);
          }
      }
      cout << x << endl; 
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