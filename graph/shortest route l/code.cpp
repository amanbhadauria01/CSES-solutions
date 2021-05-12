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
int dist[N];
 
void go(){
   cin >> n >> m ; 
   for(int i = 0 ;i < m ; i++){
     int a , b  , c ; cin >> a >> b >> c; 
     graph[a].push_back({b,c});
   }
   for(int i = 1 ; i <= n ; i++)dist[i] = inf;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   pq.push({0,1});
   while(!pq.empty()){
     int d = pq.top().fi;
     int u = pq.top().se;
     pq.pop();
     if(dist[u]<=d)continue;
     dist[u] = d;
     for(auto v : graph[u]){
       if(dist[v.fi] > dist[u] + v.se){
         pq.push({dist[u]+v.se,v.fi});
       }
     }
   }
   for(int i = 1 ; i <= n ; i++)cout << dist[i] << " " ; cout << endl;
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