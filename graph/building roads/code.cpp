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
bool vis[N] = {0};
 
 
void dfs(int u){
   vis[u] = 1;
   for(auto v : graph[u]){
     if(vis[v])continue;
     dfs(v);
   }
}
 
void go(){
    cin >> n >> m ; 
    for(int i = 0 ; i < m ; i++){
      int a , b ; cin >> a >> b ; 
      graph[a].push_back(b); graph[b].push_back(a);
    }
    vector<int> ans ; 
    dfs(1);
    for(int i = 2 ; i <= n ; i++){
      if(!vis[i])dfs(i) , ans.push_back(i); 
    }
    cout << ans.size() << endl;
    for(auto v : ans)cout << 1 << " " << v << endl; 
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