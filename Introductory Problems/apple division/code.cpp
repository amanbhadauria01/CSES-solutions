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
const int N = 1e5 + 10;
int n , a[N] ;
 
void go(){
  cin >> n ; 
  for(int i = 0 ; i< n ; i++)cin >> a[i];
  int diff = inf;
  for(int i = 0 ; i < (1<<n) ; i++){
    int sum1=0,sum2=0;
    for(int j = 0 ; j < n ; j++){
      if((i&(1<<j)))sum1+=a[j];
      else sum2+=a[j];
    }
    diff = min(diff,(int)abs(sum1-sum2));
  }
  cout << diff << endl;
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