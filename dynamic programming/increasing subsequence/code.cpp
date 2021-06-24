#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 1e6 + 10;
int n,a[N]; 

void go(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    vector<int> v(n+1,inf);
    v[0] = 0;
    for(int i = 0 ; i < n ; i++){
        int idx = lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(v[idx-1]<a[i] && a[i] < v[idx])v[idx] = a[i];
    }
    for(int i = n ; i >= 0 ; i--){
        if(v[i] < inf){
            cout << i << endl; return ;
        }
    }
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