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
  int n , x;
  cin >> n >> x ;
  vector<int> v(n);
  for(int i = 0 ; i < n ; i++)cin >> v[i] , a.insert(v[i]);
  sort(v.begin(),v.end());
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
     if(a.find(v[i])==a.end())continue;
     del(v[i]);
     cnt++;
     if(a.size()==0)break;
     int allowed = x-v[i];
     auto it = a.upper_bound(allowed);
     if(it!=a.begin())it = prev(it);
     int val = *it;
     if(val+v[i] <= x)del(val);
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