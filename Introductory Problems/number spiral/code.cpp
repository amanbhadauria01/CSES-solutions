#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18 + 1;
#define D double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 998244353;
#define fi first
#define se second
#define r(a)  (( (a%MOD) + MOD ) %MOD)
#define endl '\n'
const int N = 1e6 + 10;
int n , k , a[N]={0};
 
void solve(){
   int r , c ; cin >> r >> c; 
   int block = max(r,c)-1;
   int start = block*block;
   bool lu = (block+1)%2;
   if(lu){
       if(r<c)cout << start + 2*max(r,c) - r << endl;
       else   cout << start + c              << endl;
   }else{
       if(c<r)cout << start + 2*max(r,c) - c << endl;
       else   cout << start + r              << endl;
   }
} 
 
signed main() {
        FIO
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }
}