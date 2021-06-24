#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 2e5 + 10;
int a[N] ;

void go(){
   int x,n ;  
   cin >> x >> n ; 
   for(int i = 0 ; i < n ; i++)cin >> a[i];
   multiset<int> ms ; 
   set<int> s ;
   ms.insert(x);
   s.insert(0); s.insert(x);
   for(int i = 0 ; i < n ; i++){
       auto nxt = s.upper_bound(a[i]);
       auto prv = nxt; prv--;
       ms.erase(ms.find((*nxt)-(*prv)));
       ms.insert((*nxt)-a[i]);
       ms.insert(a[i]-(*prv));
       s.insert(a[i]);
       cout << (*ms.rbegin()) << " "; 
   }
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