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
int n;
class cl{
    public : 
    int a,b,p;
}; 

cl v[N];

bool cmp(cl & a , cl & b){
    return a.b < b.b;
}

int seg[4*N],lazy[4*N];

// this segment tree adds values for a range and finds max of a range

int fun(int a, int b){
    return max(a,b);
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
    cin >> n ;
    map<int,int> m ;
    for(int i = 0 ; i < n ; i++)cin >> v[i].a >> v[i].b >> v[i].p ;
    for(int i = 0 ; i < n ; i++)m[v[i].a]  = 0 , m[v[i].b] = 0;
    int cnt = 1;
    for(auto &i : m)i.se = cnt++;
    for(int i = 0 ; i < n ; i++){
        v[i].a = m[v[i].a];
        v[i].b = m[v[i].b];
    }
    sort(v,v+n,cmp);
    memset(seg,0,sizeof(seg)); memset(lazy,0,sizeof(lazy));
    for(int i = 0 ; i < n ; i++){
      int mx = querylazy(0,0,cnt+10,0,v[i].a-1);
      int cur = v[i].p + mx;
      int val = querylazy(0,0,cnt+10,v[i].b,v[i].b);
      int toput = max(val,cur);
      rangeUpdate(0,0,cnt+10,v[i].b,v[i].b,toput-val);
    }
    cout << querylazy(0,0,cnt+10,0,cnt+10);
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