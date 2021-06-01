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
vector<pair<int,int>> edges;
int p[N],r[N];

int findd(int x){
    if(x==p[x])return x;
    return p[x] = findd(p[x]);
}

bool joinn(int u , int v){
    u = findd(u) ; v = findd(v);
    if(u!=v){
        if(r[u]<r[v])r[u] += r[v] , p[v] = u;
        else         r[v] += r[u] , p[u] = v;
        return 1;
    }
    return 0;
}

void go(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a,b,c ; cin >> a >> b;
        edges.push_back({a,b});
    }
    for(int i = 1 ; i <= n ; i++)p[i] = i , r[i] = 1;
    int cur = n;
    int mx = 0;    
    for(int i = 0 ; i < m ; i++){
      int u = edges[i].fi , v= edges[i].se; 
      if(joinn(u,v))cur--;
      mx = max({r[findd(u)],r[findd(v)],mx});
      cout << cur << " " << mx << endl;
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