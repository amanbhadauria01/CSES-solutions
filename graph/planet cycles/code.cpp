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
int n ;
int par[N],len[N]={0};
bool vis[N] = {0}; 
int steps;

void dfs(int u,vector<int> & order){
   order.push_back(u);
   if(vis[u]){
       steps += len[u]; return ;
   }
   vis[u] = 1;
   steps++;
   dfs(par[u],order);  
}

void go(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)cin >> par[i];
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            vector<int> order;
            steps = 0;
            dfs(i,order);
            int dec = 1, j = 0;
            while(j<(int)order.size()){
               if(order[j] == order.back())dec = 0;
               len[order[j++]] = steps;
               steps -= dec;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)cout << len[i] << " " ; cout << endl;
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