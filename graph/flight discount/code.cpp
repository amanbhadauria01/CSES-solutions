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
vector<pair<int,int>> graph[N][2];
vector<pair<int,pair<int,int>>> edges;
int d[N][2];
 
void dijikstra(int x ,int z){
    for(int i = 1 ; i <= n ; i++)d[i][z] = inf;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,x});
    while(!pq.empty()){
        int u = pq.top().se;
        int cur = pq.top().fi;
        pq.pop();
        if(d[u][z]<=cur)continue;
        d[u][z] = cur;
        for(auto v : graph[u][z]){
            if(d[v.fi][z] > cur + v.se){
                pq.push({cur+v.se,v.fi});
            }
        }
    }
}
 
void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a, b , c ; cin >> a >> b >> c ; 
        edges.push_back({c,{a,b}});
        graph[a][0].push_back({b,c});
        graph[b][1].push_back({a,c});
    }
    dijikstra(1,0); dijikstra(n,1);
    int ans = d[n][0];
    for(auto i : edges){
        int x = i.se.fi , y = i.se.se , w= i.fi;
        ans = min({ans,d[x][0]+w/2+d[y][1]});
    }
    cout << ans << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
 
}