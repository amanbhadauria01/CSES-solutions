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
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    int cnt=0;
    for(int i = 1 ; i < n ; i++){
        if(a[i]<a[i-1]){cnt += a[i-1]-a[i]; a[i] = a[i-1];} 
    }
    cout << cnt ;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
}