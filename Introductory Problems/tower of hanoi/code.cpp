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
vector<pair<int,int>> v ;
 
void mover(int source ,int idx1 , int idx2 , int idx3){
  if(source==0)return ;
  mover(source-1,idx1,idx3,idx2);
  v.push_back({idx1,idx3});
  mover(source-1,idx2,idx1,idx3);
}
 
void go(){
   int n ; cin >> n ; 
   mover(n,1,2,3);
   cout << v.size()<<endl;
   for(auto i : v)cout << i.fi << " " << i.se << endl;
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