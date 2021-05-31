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
 
 
void help(int n ){
  if(n==1){
      cout << 0 << endl; return;
  }
  if(n==2){
      cout << 6 << endl; return ;
  }
 
  int num2x3 = (n-2)*(n-1);
  int num3x2 = num2x3;
  int tot    = ((n*n)*(n*n - 1))/2 - 2*num2x3 - 2*num3x2;
  cout << tot << endl;  
}
 
void go(){
  int n ; cin >> n ; 
  for(int i = 1 ; i <= n ; i++)help(i);
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