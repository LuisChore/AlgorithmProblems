#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const lli inf_int = 1e9;

int a[200010];
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
      int n;
      cin >> n;
      for(int i=0;i<n;i++){
        cin >> a[i];
      }
      int l = 0, r = n-1,j = 0;
      while(l<=r){
        if(j&1){
          cout << a[r] << " ";
          r--;
        }else{
          cout << a[l] << " ";
          l++;
        }
        j++;
      }
      cout << "\n";
  }
  return 0;
}
