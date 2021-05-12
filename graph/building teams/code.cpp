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
const int N = 1e5 + 10;
int n , m;
vector<int> graph[N];
int color[N];
bool ok = 1;
 
void dfs(int u , int c){
   if(!ok)return ;
   color[u] = c;
   for(auto v : graph[u]){
     if(color[v] == c){ ok = 0; return ; }
     if(color[v] != -1)continue;
     dfs(v,c^1);
   }
}
 
void go(){
    cin >> n >> m ; 
    memset(color,-1,sizeof(color));
    for(int i = 0 ; i < m ; i++){
      int a , b ; cin >> a >> b ; 
      graph[a].push_back(b); graph[b].push_back(a);
    } 
    for(int i = 1 ; i <= n ; i++){
      if(color[i]==-1)dfs(i,1);
    }
    if(!ok){
      cout << "IMPOSSIBLE" << endl ; return ;
    }
    for(int i =1  ; i <= n ;i++)cout << color[i]+1 << " ";
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