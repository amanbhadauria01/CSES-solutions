#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;

int power(int a, int b){
    if(b==0)return 1;
    int temp = power(a,b/2);
    temp *= temp;
    temp %= MOD ; temp += MOD ; temp %= MOD;
    if(b%2)temp *= a;
    temp %= MOD ; temp += MOD ; temp %= MOD;
    return temp;
}

void solve(){
    int a,b ; cin >> a >> b ;
    if(a==0)cout << (b==0) << endl;  
    else cout << power(a,b) << endl;
} 

signed main() {
        FIO
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }

}