#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    cin >> n;
    vector<int> L(n),R(n),v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
      L[i] = v[i];
      if(i)
        L[i] = min(L[i-1],v[i]);
    }
    for(int i=n-1;i>=0;i--){
      R[i] = v[i];
      if(i < n - 1){
        R[i] = min(v[i],R[i+1]);
      }
    }
    bool yes = true;
    int acum = 0;
    for(int i=1;i<n-1;i++){
      v[i]-=acum;
      L[i] = min(L[i-1],L[i]);
      L[i] = min(L[i],v[i]);
      if(v[i] <= L[i-1])
        continue;
      int diff = v[i] - L[i-1];
      if(R[i+1] - acum < diff){
        yes = false;
        break;
      }
      acum+=diff;
    }
    if(yes){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}
