#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1e9 + 7;
#define fi first
#define se second
#define endl '\n'
const int N = 2e6 + 10;
int n;
vector<string> paths;
bool vis[8][8] ={0};
int mover[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char dir[4]        = { 'D' , 'R' ,  'U' , 'L'};
map<char,int> m;

bool wallpartitioned(int x, int y){
    bool ok = 0;     
    if(x==0 && y>0 && y < 6 && vis[1][y]==1 && vis[0][y-1]==0 && vis[0][y+1]==0)ok = 1;
    if(x==6 && y>0 && y < 6 && vis[5][y]==1 && vis[6][y-1]==0 && vis[6][y+1]==0)ok = 1;
    if(y==0 && x>0 && x < 6 && vis[x][1]==1 && vis[x-1][0]==0 && vis[x+1][0]==0)ok = 1;
    if(y==6 && x>0 && x < 6 && vis[x][5]==1 && vis[x-1][6]==0 && vis[x+1][6]==0)ok = 1;
    return ok;
}

bool looped(int x, int y){
    if(x==0 || y == 0 || x==6 || y==6)return 0;
    bool ok = 0;
    if(vis[x-1][y] == 1 && vis[x+1][y] == 1 && vis[x][y-1] == 0 && vis[x][y+1] == 0)ok = 1;
    if(vis[x][y-1] == 1 && vis[x][y+1] == 1 && vis[x+1][y] == 0 && vis[x-1][y] == 0)ok = 1;
    return ok;
}

int rec(int i , int j , int k , string & s){
    if(i==6 && j==0){
        if(k == 48)return 1; 
        return 0;
    }
    if(k == 48)return 0;
    if(wallpartitioned(i,j))return 0;
    if(looped(i,j))return 0;
    int ans = 0;
    vis[i][j] = 1;
    if(s[k]=='?'){
        for(int z = 0 ; z < 4 ; z++){
            int ni = mover[z][0] + i;
            int nj = mover[z][1] + j;
            if(ni < 0 || nj < 0 || ni >= 7 || nj >= 7 || vis[ni][nj])continue;
            ans += rec(ni,nj,k+1,s);
        }
    }else{
        int ni = mover[m[s[k]]][0] + i ; 
        int nj = mover[m[s[k]]][1] + j ; 
        if(ni < 0 || nj < 0 || ni >= 7 || nj >= 7 || vis[ni][nj]){vis[i][j] = 0; return 0;}
        ans += rec(ni,nj,k+1,s);
    }
    vis[i][j] = 0;
    return ans;
}

void solve(){
   m['D'] = 0 ; m['R'] = 1; m['U'] = 2 ; m['L'] = 3; 
   string s; 
   cin >> s;
   cout << rec(0,0,0,s);
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}