#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 998244353;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int n , m ;
vector<int> graph[N]; 
int vis[N] = {0};
 
void dfs(int u , int p, vector<int> & st){
    vis[u] = 1;
    for(auto v : graph[u]){
        if(vis[v]==2)continue;
        if(vis[v]==1){
            cout << "IMPOSSIBLE" << endl; exit(0);
        }
        dfs(v,u,st);
    }
    vis[u] = 2;
    st.push_back(u);
}
 
void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ; cin  >> a >>  b ; graph[a].push_back(b);
    }
    vector<int> st;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]==0)dfs(i,i,st);
    }
    reverse(st.begin(),st.end());
    for(auto i : st)cout << i << " " ; cout << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
 
}