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
int n , m;
set<int> graph[N],igraph[N];
bool vis[N] = {0};
int comp[N] = {0};

void dfs1(int u,vector<int> & st){
    vis[u] = 1;
    for(auto v : graph[u]){
        if(!vis[v])dfs1(v,st);
    }
    st.push_back(u);
}

void dfs2(int u , int j ){
    vis[u] = 1;
    comp[u] = j;
    for(auto v : igraph[u]){
        if(!vis[v])dfs2(v,j);
    }
}

void go(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        graph[a].insert(b); 
        igraph[b].insert(a);
    }
    for(int i = 1 ; i <= n ; i++)vis[i] = 0;
    vector<int> st;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i])dfs1(i,st);
    }
    for(int i = 1 ; i <= n ; i++)vis[i] = 0;
    int j = 1;
    while((int)st.size()>0){
       int u = st.back(); st.pop_back();
       if(!vis[u])dfs2(u,j) , j++;
    }
    cout << j-1 << endl;
    for(int i = 1 ; i <= n ; i++)cout << comp[i] << " " ; cout <<endl;
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