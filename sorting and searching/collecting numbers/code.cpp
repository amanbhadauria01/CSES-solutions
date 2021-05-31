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
const int N = 2e5 + 10;
int n , k , a[N]={0},pos[N];
 
void solve(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)cin >> a[i] , pos[a[i]]=i;
    int cnt = 1;
    for(int i = 2 ; i <= n ; i++){
        if(pos[i-1]>pos[i])cnt++;
    }
    cout << cnt << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
}