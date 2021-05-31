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
    cin >> n ;
    if(n== 1){cout << 1 << endl; return ; }
    if(n <= 3){ cout << "NO SOLUTION" << endl; return ;}
    if(n == 4){
        cout << 3 << " " << 1 << " " << " " << 4 << " " << 2 << endl;
    }
    int cnt = 1;
    for(int i = 1 ; i <= n ; i+=2)a[i] = cnt++;
    for(int i = 2 ; i <= n ; i+=2)a[i] = cnt++;
    for(int i = 1 ; i <= n ; i++)cout << a[i] << " " ; cout << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
}