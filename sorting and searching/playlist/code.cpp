#include <bits/stdc++.h>
using namespace std;
// #define int long long 
// const int inf = 1e12;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 10;
 
void solve(){
   int n ; cin >> n ;
   vector<int> v ; 
   v.resize(n);
   for(int i = 0 ; i < n ; i++)cin >> v[i];
   int mx =1 ;
   int start = 0;
   set<int> s;
   for(int end = 0 ; end < n ; end++){
      while((int)s.size()>0 && s.find(v[end])!=s.end()){
         auto it = s.find(v[start]);
         if(it!=s.end())s.erase(it);
         start++;
      } 
      mx = max(mx,end-start+1);
      s.insert(v[end]);
   }
   cout << mx << endl;
} 
 
signed main() {
        FIO
        int t = 1;
      //   cin >> t;
        while(t--){
            solve();
        }
 
}