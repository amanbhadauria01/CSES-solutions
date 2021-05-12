#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int n , m ; 
vector<int> graph[N];
vector<pair<int,pair<int,int>>> edges;
int dist[N];
int par[N] ;
 
void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a, b , c ; cin >> a >> b >> c ; 
        edges.push_back({c,{a,b}});
        graph[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)dist[i]=inf , par[i] = i;
    dist[1] = 0;
    int x;
    for(int i = 1 ; i <= n ; i++){
        x = -1;
        for(int j = 0 ; j < m ; j++){
            int a = edges[j].se.fi , b = edges[j].se.se , c = edges[j].fi;
            if(dist[a]+c < dist[b])dist[b] = dist[a]+c , x = b , par[b] = a;
        }
    } 
    if(x==-1){cout << "NO" << endl; return ;}
    for(int i = 1 ; i <= n ; i++)x = par[x];
    int o = x;
    vector<int> ans ; x = par[x];
    ans.push_back(o);
    while(x!=o)ans.push_back(x) , x = par[x];
    ans.push_back(o);
    reverse(ans.begin(),ans.end());
    cout << "YES" << endl; 
    for(auto i : ans)cout << i << " " ; cout << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
 
}