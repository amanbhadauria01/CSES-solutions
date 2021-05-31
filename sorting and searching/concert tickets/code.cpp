#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e17;
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
multiset<int> a;
 
void del(int x){
  auto it = a.find(x);
  if(it!=a.end())a.erase(it);
}
 
void go(){  
  int n , m;
  cin >> n >> m ;
  for(int i = 0 ; i < n ; i++){
    int x ; cin >> x ; a.insert(x);
  }
  vector<int> v(m);
  for(int i = 0 ; i < m ; i++)cin >> v[i];
  vector<int> ans(m,-1);
  for(int i = 0 ; i < m ; i++){
    if(a.size()==0)break;
    auto it = a.upper_bound(v[i]);
    if(it != a.begin())it = prev(it);
    int x = *it;
    if(x <= v[i]){
      ans[i] = x;
      del(x);
    }
  }
  for(auto &i : ans)cout << i << endl;
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