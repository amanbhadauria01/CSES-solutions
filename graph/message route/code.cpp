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
int dist[N];
 
void go(){
    cin >> n >> m ; 
    for(int i = 0 ; i < m ; i++){
      int a , b ; cin >> a >> b ; 
      graph[a].push_back(b); graph[b].push_back(a);
    } 
    for(int i = 1 ; i <= n ; i++)dist[i] = inf;
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
      int d = q.front().fi;
      int u = q.front().se;
      q.pop();
      if(d>=dist[u])continue;
      dist[u] = d;
      for(auto v : graph[u]) {
        if(dist[v] > d+1)q.push({d+1,v});
      }
    }
    if(dist[n] == inf){cout << "IMPOSSIBLE" << endl; return ;}
    vector<int> ans ;
    int u = n;
    while(u!=1){
        ans.push_back(u); 
        for(auto v : graph[u])if(dist[v] == dist[u]-1){u = v; break;}
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl; 
    for(auto i : ans)cout << i << " " ; cout << endl;
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