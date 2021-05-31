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
  return a.fi < b.fi;
}
 
void go(){  
  int n , x ;
  cin >> n >> x;
  vector<pair<int,int>> v(n);
  int j = 0;
  for(auto &i : v)cin >> i.fi , i.se = j++ ;
  sort(v.begin(),v.end());
  int i = 0 ; j = n-1;
  while(i<j){
    int sum = v[i].fi + v[j].fi;
    if(sum == x){
      cout << v[i].se+1 << " " << v[j].se+1 << endl; return ;
    }
    if(sum < x){
      i++;
    }else{
      j--;
    }
  }
  cout << "IMPOSSIBLE" << endl;
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