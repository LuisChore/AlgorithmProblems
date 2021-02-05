#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

typedef tree<
lli,
null_type,//mapped key
less<lli>,//comp
rb_tree_tag,
tree_order_statistics_node_update
>ordered_set;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
      cin >> s[i];
    }
    if(m&1){
      cout << "YES\n";
      for(int i=0;i<m+1;i++){
        if(i&1)
          cout << 1 << " ";
        else
          cout << 2 << " ";
      }
      cout << "\n";
      continue;
    }

    bool yes = false;
    int a=0,b=0,c=0;
    for(int i=0;i<n && !yes;i++){
      for(int j=0;j<n;j++){
        if(i!=j && s[i][j] == s[j][i]){
          a = i + 1;
          b = j + 1;
          yes = true;
          break;
        }
      }
    }
    if(yes){
      cout << "YES\n";
      for(int i=0;i<m+1;i++){
        if(i&1)
          cout << a << " ";
        else
          cout << b << " ";
      }
      cout << "\n";
      continue;
    }

    for(int i=0;i<n && !yes;i++){
      b = -1;
      c = -1;
      for(int j=0;j<n;j++){
        if(s[j][i] == 'a'){
          b = j+1;
        }
        if(s[i][j] == 'a'){
          c = j+1;
        }
      }
      if(b!=-1 && c != -1){
        a = i+1;
        yes = true;
        break;
      }
      b = -1;
      c = -1;
      for(int j=0;j<n;j++){
        if(s[j][i] == 'b'){
          b = j+1;
        }
        if(s[i][j] == 'b'){
          c = j+1;
        }
      }
      if(b!=-1 && c != -1){
        a = i + 1;
        yes = true;
        break;
      }
    }

    if(!yes){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if((m/2)&1){
      vector<int> ans ={b,a,c,a};
      for(int i=0;i<m+1;i++){
        cout << ans[i%4] << " ";
      }cout << "\n";
    }else{
      int left = (m-2)/2;
      vector<int> ans ={a,b};
      for(int i=0;i<left+1;i++){
        cout << ans[i%2] << " ";
      }
      cout << a << " " << c << " ";
      ans[0] = a;
      ans[1] = c;
      for(int i=0;i<left;i++){
        cout << ans[i%2] << " ";
      }cout << "\n";
    }

  }
  return 0;
}
