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
const int N = 1e6 + 10;
int a[N];
int n ;
 
void go(){  
  
  cin >> n ;
  for(int i=0 ; i < n ; i++)cin >> a[i];
  sort(a,a+n);
  int ans;
  int k = 0;
  for(int i = 0  ; i<n ; i++){
     if(a[i]>k+1){cout << k+1 << endl; return ;}
     else k += a[i];
  }
  cout << k+1 << endl;
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