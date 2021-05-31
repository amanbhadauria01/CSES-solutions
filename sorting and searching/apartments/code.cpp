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
multiset<int> b;
 
void del(int x){
  auto it = b.find(x);
  if(it!=b.end())b.erase(it);
}
 
void go(){  
  int n , m , k ;
  cin >> n >> m >> k ; 
  vector<int> a(n);
  int cnt = 0;
  for(int i = 0 ; i < n ; i++)cin >> a[i];
  sort(a.begin(),a.end());
  for(int i = 0 ; i < m ; i++){
    int x ; cin >> x ; b.insert(x);
  }
  for(int i = 0 ; i < n ; i++){
    auto it = b.lower_bound((a[i]-k));
    if(it==b.end())continue;
    int val = *it;
    if(val > a[i]+k)continue;
    cnt++;
    del(val); 
  }
  cout << cnt;
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