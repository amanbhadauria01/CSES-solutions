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
 
// a = 2*x + y
// b = x   + 2*y
// 2b-a = 3y --> y = (2b-a)/3
// x = (a-y)/2 --> x = (a-(2b-a)/3)/2 == (3a-2b+a)/6 == (4a-2b)/6 == (2a-b)/3
 
 
void go(){
   int a,b;
   cin >> a >> b ; 
   if(((2*a-b)%3) || (((2*b-a)%3)) || (2*a < b) || (2*b < a)){
       cout << "NO" << endl; return;
   }
   cout << "YES" << endl;
} 
 
signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        cin >> t;
        int cases = 1;
        while(t--){
            // cout << "Case #" << cases << ": "; cases++;
            go();
        }
 
}