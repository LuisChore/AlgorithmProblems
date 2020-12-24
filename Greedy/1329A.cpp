#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  lli sum = 0;
  cin >> n >> m;
  vector<int> Len(n+1);
  vector<int> X(n+1);
  for(int i=1;i<=m;i++){
    cin >> Len[i];
    sum += Len[i];
  }
  if(sum < n){
    cout << -1 << "\n";
    return 0;
  }
  int top = 0;
  for(int i=m;i>=1;i--){
    if(Len[i]<=top + 1){
      X[i] = top - Len[i] + 2;
      top++;
    }else{
      X[i] = 1;
      top = Len[i];
    }
  }

  if(top > n){
    cout << -1 << "\n";
    return 0;
  }
  int L = n;
  for(int i=1;i<=m;i++){
    if(X[i] + Len[i] - 1 < L){
      X[i] = L - Len[i] + 1;
      L = X[i] - 1;
    }else{
      break;
    }
  }
  for(int i=1;i<=m;i++){
    cout << X[i] << " ";
  }
  cout << "\n";
}
