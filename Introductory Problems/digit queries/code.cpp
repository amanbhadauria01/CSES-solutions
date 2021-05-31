#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e17;
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
int digit[20]={0};
int numm[20]={0};
 
int findd(int x){
   int idx = 0;
   for(int i = 0 ; i <= 18 ; i++){
     if(numm[i]>x)break;
     idx = i;
   }
   int temp = x-numm[idx];
   int ans = temp*(idx+1) + digit[idx];
   return ans;
}
 
void go(){  
  int k ; cin >> k ;
  int l = 0 , r = inf;
  int ans = 0;
  while(l<=r){
    int m = (l+r)/2;
    int num = findd(m);
    if(num<k){
      ans = m;
      l = m+1;
    }else{
      r = m-1;
    }
  }
  k -=  findd(ans);
  int bit[20] = {0};
  int x = ans+1 ;
  int j = 19;
  while(x>0){
    bit[j--] = ( x%10 + 10 )%10; 
    x /= 10;
  }
  j++;
  cout << bit[j+k-1] << endl;
}  
 
signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        digit[0] = 0;
        numm[0] = 0;
        int b = 1;
        for(int i = 1 ; i <= 18 ; i++){
          digit[i] = i*b*9 + digit[i-1];
          numm[i] = b*9 + numm[i-1];
          b *= 10;
        }
     
        cin >> t;
        while(t--){
            // cout << "Case #" << cases << ": ";
            go();
        }
 
}