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
const int N = 2e5 + 10;
int n  , q , a[N] ;

int seg[4*N],lazy[4*N];

// this segment tree adds values for a range and finds max of a range

int fun(int a, int b){
    return a^b;
}

void build(int ind , int low , int high){
    if(low == high){
         seg[ind] = a[low];
         return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = fun(seg[2*ind+1],seg[2*ind+2]);
}

void rangeUpdate(int ind, int low , int high , int l , int r , int val){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    // completely outside
    if(r < low || l > high ||  low > high ) return;
    // completely inside
    if(low >= l && high <= r){
       seg[ind] += (high-low+1)*val;
       if(low != high){
           lazy[2*ind+1] += val;
           lazy[2*ind+2] += val;
       }
       return;
    }
    // rest
    int mid = (low + high)/2;
    rangeUpdate(2*ind+1,low,mid,l,r,val);
    rangeUpdate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = fun(seg[2*ind+1],seg[2*ind+2]);
}

int querylazy(int ind , int low, int high, int l , int r ){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    // completely outside
    if(r < low || l > high || low > high) return 0;
    // completely inside
    if(l <= low && high <= r) return seg[ind];
    // rest
    int mid = (low+high)/2;
    return fun(querylazy(2*ind+1,low,mid,l,r),querylazy(2*ind+2,mid+1,high,l,r));
}



void go(){
    cin >> n >> q ; 
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    build(0,0,n-1);
    for(int i = 1 ; i <= q ; i++){
       int t ; cin >> t ; 
       if(t==1){
           int a,b,u ; cin >> a >> b >> u ; a-- ; b-- ;
           rangeUpdate(0,0,n-1,a,b,u);
       }else{
           int k ; cin  >> k ; k--;
           cout << querylazy(0,0,n-1,k,k) << endl;
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