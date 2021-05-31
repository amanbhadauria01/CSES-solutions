#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1e9 + 7;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int n , m ;
vector<int> graph[N]; 
int dp[N];

int dfs(int u){
    int & ans = dp[u];
    if(ans != -1)return ans;
    if(u==n)return ans = 0;
    ans = -inf;
    for(auto v : graph[u]){
        ans = max(ans,dfs(v)+1);
    }
    if(ans < 0)ans = -inf;
    return ans;
}

void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ; cin  >> a >>  b ; graph[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    int ans = dfs(1); 
    if(ans < 0){ cout << "IMPOSSIBLE" << endl; return ; }
    cout << ans + 1 << endl;
    int u = 1;
    while(1){
      cout << u << " ";
      if(u==n)break;
      for(auto v : graph[u]){
          if(dp[v]==dp[u]-1){u=v; break;}
      }
    } 
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}