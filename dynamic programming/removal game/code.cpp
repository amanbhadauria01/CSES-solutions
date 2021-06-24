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
const int N = 1e5 + 10;
int n; 
int dp[5001][5001][2];
int a[5001];

int rec(int i , int j , int z){
   if(i>j)return 0;
   int & ans = dp[i][j][z];
   if(ans != -1)return ans;
   if(z){
      ans = -inf;
      ans = max({ ans,rec(i+1,j,0)+a[i], rec(i,j-1,0)+a[j]});
   }else{
      ans = inf;
      ans = min({ ans,rec(i+1,j,1)-a[i], rec(i,j-1,1)-a[j]});
   }
   return ans;
}

void go(){
    cin >> n ;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)cin >> a[i] , sum += a[i];
    memset(dp,-1,sizeof(dp));
    int diff = rec(0,n-1,1);
    cout << sum - (sum-diff)/2 << endl;
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