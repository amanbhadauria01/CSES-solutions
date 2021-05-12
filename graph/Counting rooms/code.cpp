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
const int N = 1e3 + 10;
int mover[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
vector<string> v ; 
int n , m ; 
 
void dfs(int x ,int y){
   v[x][y] = '#';
   for(int k = 0 ; k < 4 ; k++){
       int nx = x + mover[k][0];
       int ny = y + mover[k][1];
       if(nx < 0 || ny < 0 || nx == n || ny == m || v[nx][ny]=='#')continue;
       dfs(nx,ny);
   } 
}
 
void go(){
  cin >> n >> m; 
  v.resize(n);
  for(int i = 0 ; i < n ; i++)cin >> v[i];
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
          if(v[i][j]=='.'){
              dfs(i,j);
              cnt++;
          }
      }
  }
  cout << cnt;
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