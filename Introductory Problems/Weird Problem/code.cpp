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
const int N = 1e5 + 10;
int n , k , a[N];
 
void solve(){
    cin >> n ;
    vector<int> v ; 
    while(n>1){
        v.push_back(n);
        if(n%2) n = n*3 + 1;
        else    n /= 2;
    }
    v.push_back(1);
    for(auto i : v)cout << i << " " ;  cout << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
}