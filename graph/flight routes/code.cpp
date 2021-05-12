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
int n , m , k ; 
vector<pair<int,int>> graph[N];
multiset<int> dist[N];

void solve(){
    cin >> n >> m >> k ;
    for(int i = 0 ; i < m ; i++){
        int a, b , c ; cin >> a >> b >> c ; 
        graph[a].push_back({b,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    // shows that the first time we reach a node is its closest distance
    // then the second time we reach a node is its second closest distance and so on.. 
    while(!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();
        if((int)dist[u].size() >= k )continue;
        dist[u].insert(d);
        for(auto v : graph[u]){
            if((int)dist[v.fi].size() < k){
                pq.push({v.se+d,v.fi});
            }
        }
    }
    for(auto i : dist[n])cout << i << " " ; cout << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}