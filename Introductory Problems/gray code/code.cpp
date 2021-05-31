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
 
int n ;
 
int gray(int x){
    return x^(x>>1);
}
 
void bin(int x){
    int j = n-1;
    vector<int> bit(n,0);
    while(x>0){
        if(x%2)bit[j] =1 ; x/=2 ; j--;
    } 
    for(auto i : bit)cout << i ; cout << endl;
}
 
void go(){
   cin >> n ; 
  string temp;
  for(int i = 0; i < n ; i++)temp.push_back('0');
  vector<int> v;
  for(int i = 0 ; i < (1<<n) ; i++){
     int g = gray(i);
     v.push_back(g);
  }
  for(auto i : v)bin(i);
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