#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1e9 + 7;
#define fi first
#define se second
#define endl '\n'
const int N = 2e6 + 10;
int n , a[N];

void solve(){
   cin >> n ;
   for(int i = 0 ; i < n ; i++)cin >> a[i];
   vector<int> v(n+1,inf);
   v[0] = 0;
   for(int i = 0 ; i < n ; i++){
       int idx = upper_bound(v.begin(),v.end(),a[i])-v.begin();
       if(v[idx-1]<=a[i] && a[i] < v[idx]) v[idx] = a[i];
   }
   for(int i = n ; i >= 0 ; i--){
       if(v[i]<inf){
           cout << i << endl ;return;
       }
   }
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}