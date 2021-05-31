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
int par[N]={0},vis[N]={0};

void dfs(int u , int p){
    par[u] = p;
    vis[u] = 1;
    for(auto v : graph[u]){
        if(vis[v]==1){
            int x = u; 
            vector<int> ans; ans.push_back(v);
            while(x!=v){ans.push_back(x) ; x = par[x] ; }
            ans.push_back(v);
            reverse(ans.begin(),ans.end());
            cout <<  ans.size() << endl;
            for(auto i : ans)cout << i << " " ; cout << endl;
            exit(0);
        }
        if(vis[v]==2)continue;
        dfs(v,u);
    }
    vis[u] = 2;
}

void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ; cin  >> a >>  b ; graph[a].push_back(b);
    }
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]==0)dfs(i,i);
    }
    cout << "IMPOSSIBLE" << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}