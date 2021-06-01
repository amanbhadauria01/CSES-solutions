#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
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
int n , m ;
vector<pair<int,int>> graph[N];
int mnroutes[N]={0},mxroutes[N]={0},dist[N],routes[N]={0};

void go(){
  cin >> n >> m ; 
  for(int i = 0 ; i < m ; i++){
      int a , b , c ; cin >> a >> b >> c ; 
      graph[a].push_back({b,c});
  }
  for(int i = 1 ; i <= n ; i++)dist[i] = inf;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,1});
  dist[1] = 0;
  routes[1] = 1;
  mxroutes[1] = 0;
  mnroutes[1] = 0;
  while(!pq.empty()){
     int u = pq.top().se;
     int d = pq.top().fi ; 
     pq.pop();
     if(dist[u]<d)continue;
     for(auto v : graph[u]){
        if(dist[v.fi]==d+v.se){
            mxroutes[v.fi] = max(mxroutes[u]+1,mxroutes[v.fi]);
            mnroutes[v.fi] = min(mnroutes[u]+1,mnroutes[v.fi]);
            routes[v.fi] += routes[u]; routes[v.fi] %= MOD; routes[v.fi] += MOD ; routes[v.fi] %= MOD; 
        }
        if(dist[v.fi]>d+v.se){
            routes[v.fi] = routes[u];
            mxroutes[v.fi] = mxroutes[u]+1;
            mnroutes[v.fi] = mnroutes[u]+1;
            dist[v.fi] = d+v.se;
            pq.push({d+v.se,v.fi});
        } 
     }
  }
  cout << dist[n] << " " << routes[n] << " " << mnroutes[n] << " " << mxroutes[n] << endl;
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