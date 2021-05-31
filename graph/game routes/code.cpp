#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1e9 + 7;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int n , m ;
vector<int> graph[N]; 
int dp[N];

int dfs(int u , int p){
    int & ans = dp[u];
    if(ans != -1)return ans;
    if(u==n)return 1;
    ans = 0;
    for(auto v : graph[u]){
        ans += dfs(v,u);
        ans %= MOD ; ans += MOD; ans %= MOD;
    }
    return ans;
}

void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ; cin  >> a >>  b ; graph[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(1,1) << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}