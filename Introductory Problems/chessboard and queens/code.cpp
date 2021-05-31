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
vector<string> v(8);
 
// d1
// #**
// *#*
// **#
 
bool checkcol(int x , int y , int mask){
  if(((1<<y)&mask))return 1;
  return 0;
}
 
bool checkd1(int x, int y , int mask ){
  int diff = x-y + 8;
  if(((1<<diff)&mask))return 1;
  return 0;
}
 
bool checkd2(int x, int y , int mask){
  int diff = x+y;
  if(((1<<diff)&mask))return 1;
  return 0;
}
 
int rec(int row,int colmask , int d1mask , int d2mask){
   if(row==8)return 1;
   int ans = 0;
   for(int i = 0 ; i < 8 ; i++){
      if(v[row][i]=='*')continue;
      if(checkcol(row,i,colmask))continue;
      if(checkd1(row,i,d1mask))continue;
      if(checkd2(row,i,d2mask))continue;
      ans += rec(row+1,(colmask|(1<<i)),(d1mask|(1<<(row-i+8))),
             (d2mask|(1<<(row+i)))); 
   }
   return ans;
}
 
void go(){  
  for(int i = 0 ; i < 8 ; i++)cin >> v[i];
  cout << rec(0,0,0,0);
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