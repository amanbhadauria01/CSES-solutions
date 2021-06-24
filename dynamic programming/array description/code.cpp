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
int n , m ; 
int a[N],dp[N][101];

int rec(int i , int prev){
    if(i==n)return 1;
    int & ans = dp[i][prev];
    if(ans != -1)return ans;
    ans = 0;
    if(a[i]==0){
        // prev - 1
        if(prev-1 >= 1)ans += rec(i+1,prev-1);
        // prev + 1
        if(prev+1 <= m)ans += rec(i+1,prev+1);
        // prev
        ans += rec(i+1,prev);

        ans %= MOD ; ans += MOD ; ans %= MOD;
    }else{
        if(abs(prev-a[i])>1)ans = 0;
        else ans = rec(i+1,a[i]);
    }
    return ans;
}

void go(){
   cin >> n >> m ; 
   for(int i = 0 ;  i < n; i++)cin >> a[i];
   int ans = 0;
   memset(dp,-1,sizeof(dp));
   if(a[0]==0){
       for(int j = 1 ; j <= m ; j++){ ans += rec(1,j); ans %= MOD ;ans += MOD ; ans %= MOD;}
   }else{
       ans = rec(1,a[0]);
   }
   cout << ans << endl;
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