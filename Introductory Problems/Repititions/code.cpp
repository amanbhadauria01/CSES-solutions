#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18 + 1;
#define D double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 998244353;
#define fi first
#define se second
#define r(a)  (( (a%MOD) + MOD ) %MOD)
#define endl '\n'
const int N = 1e6 + 10;
int n , k , a[N]={0},pos[N];
 
void solve(){
  string s ; cin >> s ;
  int mx = 1 , cur = 1;
  for(int i = 1 ; i < (int)s.size() ; i++){
      mx = max(cur,mx);
      if(s[i]==s[i-1])cur++;
      else cur = 1;
      mx = max(cur,mx);
  }
  cout << mx << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
}