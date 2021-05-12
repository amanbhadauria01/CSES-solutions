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
const int N = 1e3 + 10;
int mover[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char dir[]      = {'U'   ,'L'   ,'D'  ,'R'};
vector<string> v ; 
int n , m ; 
int dist[N][N];
 
void dfs(int x ,int y){
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
   pq.push({0,{x,y}});
   while(!pq.empty()){
       int d = pq.top().fi;
       int x = pq.top().se.fi;
       int y = pq.top().se.se;
       pq.pop();
       if(d>=dist[x][y])continue;
       dist[x][y] = d;
       for(int k = 0 ; k < 4 ; k++){
           int nx = x + mover[k][0];
           int ny = y + mover[k][1];
           if(nx < 0 || ny < 0 || nx == n || ny == m || v[nx][ny]=='#')continue;
           if(dist[nx][ny] <= d+1)continue;
           pq.push({d+1,{nx,ny}});
       }
   }
}
 
void bfs1(int x ,int y,vector<char> & ans){
    if(v[x][y]=='B')return;
    for(int k = 0 ; k < 4 ; k++){
        int nx = x + mover[k][0];
        int ny = y + mover[k][1];
        if(nx < 0 || ny < 0 || nx == n || ny == m || v[nx][ny]=='#')continue;  
        if(dist[nx][ny]+1==dist[x][y]){
            ans.push_back(dir[k]);
            bfs1(nx,ny,ans);
            return;
        }      
    }
}
 
void go(){
  cin >> n >> m; 
  v.resize(n);
  for(int i = 0 ; i < n ; i++)cin >> v[i];
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++)
       dist[i][j] = inf;
  }
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
          if(v[i][j]=='B'){
              dfs(i,j);
          }
      }
  }
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
          if(v[i][j]=='A'){
              if(dist[i][j]==inf){
                  cout << "NO" << endl; return ;
              }
              vector<char> ans ;
              bfs1(i,j,ans);
              cout << "YES" << endl;
              cout << ans.size() << endl; 
              for(auto i : ans)cout << i;
          }
      }
  } 
} 
 
signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        int cases = 1;
        while(t--){
            // cout << "Case #" << cases << ": "; cases++;
            go();
        }
 
}