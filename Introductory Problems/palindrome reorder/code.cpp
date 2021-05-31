#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
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
 
void go(){
  string s; cin >> s; 
  map<char,int> m ;
  for(auto &i : s)m[i]++;
  bool ok = 1;
  deque<char> v;
  for(auto &i : m){
      if((i.se)%2 == 1){
          v.push_back(i.fi);
          i.se--;
      }
  }
  if(v.size()>1){cout << "NO SOLUTION" << endl; return ;}
  for(auto &i : m){
      int cnt = i.se;
      while(cnt>0){
          v.push_back(i.fi);
          v.push_front(i.fi);
          cnt-=2;
      }
  }
  for(auto i : v)cout << i;
} 
 
signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        int cases = 1;
        while(t--){
            // cout << "Case #" << cases << ": "; cases++;
            go();
        }
 
}