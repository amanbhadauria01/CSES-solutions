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
int n , m , sz;
vector<int> a,b;
int dp[20][12][2][2][2];

void fun(vector<int> & v , int x){
    while(x>0){
        v.push_back(x%10); x/=10;
    }
}
int rec(int i ,int prev , bool f1 , bool f2, bool started){
   if(i>=sz)return 1;
   int mn = (f1 ? 0 : a[i]);
   int mx = (f2 ? 9 : b[i]);
   int & ans = dp[i][prev][f1][f2][started];
   if(ans != -1)return ans;
   ans = 0; 
   for(int j = mn ; j <= mx ; j++){
       if(started && prev == j)continue;
       ans += rec(i+1,j,(f1||(j>mn)),(f2||(j<mx)),(started||j>0));
   }
   return ans;
}

void go(){ 
   cin >> n >> m ;
   fun(a,n); fun(b,m);
   while((int)a.size() < (int)b.size())a.push_back(0);
   reverse(a.begin(),a.end()); reverse(b.begin(),b.end());
   sz = a.size();
   memset(dp,-1,sizeof(dp));
   cout << rec(0,10,0,0,0);
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