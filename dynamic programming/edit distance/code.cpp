#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 1e6 + 10;
int n , m; 
int dp[5001][5001];
string a,b; 

int rec(int i , int j){
    if(i==n){
        return m-j;
    }
    if(j==m){
        return n-i;
    }
    int & ans = dp[i][j];
    if(ans != -1)return ans; 
    ans = inf;
    // 
    if(a[i]==b[j]){
       ans = min(ans,rec(i+1,j+1));
    }
    // replace i
    ans = min(ans,rec(i+1,j+1)+1);
    // delete i
    ans = min(ans,rec(i+1,j)+1);
    // insert j
    ans = min(ans,rec(i,j+1)+1);
    return ans;
}

void go(){
    cin >> a >> b ;
    n = a.size() , m = b.size();
    memset(dp,-1,sizeof(dp));
    cout << rec(0,0);
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