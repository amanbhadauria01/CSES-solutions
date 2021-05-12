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
class cl{
  public : 
  int a , b , x;
};
 
cl edges[N];
int score[N];
vector<int> graph[N];
bool visited[N] = {0} , vis[N] = {0};
void dfs(int u){
   visited[u] = 1;
   if(vis[u]){
       cout << -1 << endl; 
       exit(0);
   }
   for(auto v : graph[u]){
       if(visited[v])continue;
       dfs(v);
   }
} 
 
void go(){
   cin >> n >> m ; 
   for(int i = 0 ; i < m ; i++){
     cin >> edges[i].a >> edges[i].b >> edges[i].x;
     graph[edges[i].b].push_back(edges[i].a);
   }
   for(int i = 0 ; i <= n ; i++ )score[i] = -inf;
   score[1] = 0;
   for(int i = 0 ; i < n-1 ; i++){
     for(int j = 0 ; j < m ; j++){
       int u = edges[j].a , v = edges[j].b , w = edges[j].x ; 
       if(score[u]>-inf && score[u]+w > score[v])score[v] = score[u] + w;
     }
   }
   vector<int> temp(n+1);
   for(int i = 1 ; i <= n ; i++)temp[i] = score[i];
   for(int j = 0 ; j < m ; j++){
     int u = edges[j].a , v = edges[j].b , w = edges[j].x ; 
     if(score[u]>-inf &&  score[u]+w > score[v])score[v] = score[u] + w;
   }
   for(int i = 1 ; i <= n ; i++)if(temp[i]!=score[i]){
     vis[i] = 1;
   }   
   dfs(n);
   cout << score[n] << endl;
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