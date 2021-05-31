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
// multiset<int> a;
 
// void del(int x){
//   auto it = a.find(x);
//   if(it!=a.end())a.erase(it);
// }
 
bool cmp(pair<int,int> a , pair<int,int> b){
  return a.se < b.se;
}
 
void go(){  
  int n ;
  cin >> n;
  vector<pair<int,int>> v;
  for(int i = 0 ; i < n ; i++){
    int x, y ; cin >> x >> y ; 
    v.push_back({x,y});
  }
  sort(v.begin(),v.end(),cmp);
  int cnt = 0;
  int curtime = 0;
  for(int i = 0 ; i < n ; i++){
    if(curtime <= v[i].fi){
      cnt++;
      curtime = v[i].se;
    }
  }
  cout << cnt << endl;
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