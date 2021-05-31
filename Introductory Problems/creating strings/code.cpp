#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int n  ;
bool visited[10];
set<string> v;
 
int cnt = 0;
 
void rec(int sz , string & temp , string & s ){
  if(sz == (int)s.size()){
    v.insert(temp); return ;
  }
  for(int i = 0 ; i < (int)s.size() ; i++){
    if(!visited[i]){
      temp.push_back(s[i]);
      visited[i] = 1;
      rec(sz+1,temp,s);
      visited[i] = 0;
      temp.pop_back();
    }
  }
}
 
void solve(){
  string s; cin >> s; 
  memset(visited,false,sizeof(visited));
  string temp;
  rec(0,temp,s);
  cout << v.size() << endl;
  for(auto &i : v)cout<< i << endl;
} 
 
signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
 
}