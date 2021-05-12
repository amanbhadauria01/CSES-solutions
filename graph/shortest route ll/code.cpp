#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
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
const int N = 1e5 + 10;
int n , m , q;
int a[501][501]; 
 
void go(){
  cin >> n >> m >> q ; 
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
       a[i][j] = inf ;
  for(int i = 1 ; i <= n ; i++)
     a[i][i] = 0;     
  for(int i = 0 ; i < m ;i++){
    int u, v , c ; cin >> u >> v >> c ;
    a[u][v] = min(a[u][v],c);
    a[v][u] = a[u][v];
  }
  for(int k = 1 ; k <= n ; k++){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
        a[i][j] = min(a[i][j],a[j][k]+a[k][i]);
        a[i][j] = min(a[i][j],a[j][i]);
        a[j][i] = a[i][j];
      }
    }
  }
  for(int i = 0 ; i < q ; i++){
    int u , v ; cin >> u >> v ; 
    if(a[u][v]==inf)cout << -1 << endl; 
    else cout << a[u][v] << endl;
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