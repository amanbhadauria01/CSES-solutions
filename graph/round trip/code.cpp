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
int vis[N]={0};
int par[N]={0};
 
void dfs(int u , int p = -1){
   par[u]=p;
   vis[u]=1;
   for(auto v : graph[u]){
     if(!vis[v])dfs(v,u);
     else if(v!=p){
       int cur = u;
       vector<int> ans ;
       ans.push_back(v);
       while(cur!=v)ans.push_back(cur) , cur = par[cur];
       ans.push_back(v);
       cout << ans.size() << endl; 
       for(auto i : ans)cout << i << " "; cout << endl;
       exit(0);
     }
   }
}
 
void go(){
    cin >> n >> m ; 
    for(int i = 0 ; i < m ; i++){
      int a , b ; cin >> a >> b ; 
      graph[a].push_back(b); graph[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++){
      if(!vis[i])dfs(i);
    }
    cout << "IMPOSSIBLE" << endl;
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