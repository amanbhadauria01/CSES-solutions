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
int n , m ;
vector<string> a;
int dist[1001][1001] , dist2[1001][1001];
int mover[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
char dir[4]     = {  'L', 'U' ,  'D' , 'R' };  
void go(){
    cin >> n >> m ; 
    a.resize(n);
    for(int i = 0 ; i < n ; i++)
       for(int j = 0 ; j < m ; j++)
          dist[i][j] = inf , dist2[i][j] = inf;
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    queue<pair<int,pair<int,int>>> q;
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < m ; j++)
          if(a[i][j]=='M')q.push({0,{i,j}});
    while(!q.empty()){
      int d = q.front().fi;
      int i = q.front().se.fi;
      int j = q.front().se.se;
      q.pop();
      if(dist[i][j] <= d)continue;
      dist[i][j] = d;
      for(int k = 0 ; k < 4 ; k++){
        int ni = i + mover[k][0];
        int nj = j + mover[k][1];
        if(ni < 0 || nj < 0 || ni >= n || nj >= m || a[ni][nj] =='#')continue;
        if(dist[ni][nj]>d+1){
          q.push({d+1,{ni,nj}});
        }
      }
    }      
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < m ; j++)
          if(a[i][j]=='A')q.push({0,{i,j}});
    while(!q.empty()){
      int d = q.front().fi;
      int i = q.front().se.fi;
      int j = q.front().se.se;
      q.pop();
      if(dist2[i][j] <= d)continue;
      dist2[i][j] = d;
      for(int k = 0 ; k < 4 ; k++){
        int ni = i + mover[k][0];
        int nj = j + mover[k][1];
        if(ni < 0 || nj < 0 || ni >= n || nj >= m || a[ni][nj] =='#')continue;
        if(dist2[ni][nj]>d+1 && dist[ni][nj] > d+1){
          q.push({d+1,{ni,nj}});
        } 
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(i==0 || i==n-1 || j==0 || j==m-1){
          if(dist2[i][j]<inf){
            cout << "YES" << endl ;
            vector<char> ans;
            int x = i , y = j ; 
            while(a[x][y]!='A'  ){
              for(int k = 0 ; k < 4 ; k++){
                int nx = x + mover[k][0];
                int ny = y + mover[k][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny]=='#')continue;
                if(dist2[nx][ny]+1 == dist2[x][y]){
                  ans.push_back(dir[k]);
                  x = nx;
                  y = ny;
                  break;
                }
              }
            }
            reverse(ans.begin(),ans.end());
            cout << ans.size() << endl;
            for(auto ch : ans)cout << ch ; 
            cout << endl; return ;
          }
        }
      }
    }
    cout << "NO" << endl;
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