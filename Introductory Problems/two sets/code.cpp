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
  int n ; cin >> n ; 
  int sum = (n*(n+1))/2;
  if(sum%2){
      cout << "NO" << endl; return ;
  }
  vector<int> v1,v2;
  sum /=2;
  for(int i = n ; i >= 1 ; i--){
      if(i <= sum){v1.push_back(i); sum -= i ;}else v2.push_back(i);
  }
  cout << "YES" << endl;
  assert(sum==0);
  cout << v1.size() << endl; 
  for(auto i : v1)cout << i << " " ; cout << endl; 
  cout << v2.size() << endl; 
  for(auto i : v2)cout << i << " " ; cout << endl;
 
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