#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  vector<vector<lli>> a;
  int n;
  a.assign(25,vector<lli>(25,0));
  while(cin >> n >> a[n][1]){
    for(int j=1;j<=n;j++){
      for(int i=n;i>=j;i--){
        if(i == n && j == 1)
          continue;

        if(i == n){
          a[i][j] = 2LL * a[i][j-1];
          continue;
        }

        if(j == 1){
          a[i][j] = 2LL * a[i+1][j];
          continue;
        }

        lli S1 = a[i+1][j] + a[i+1][1];
        lli S2 = a[i][j-1] + a[n][j-1];
        a[i][j] = S1 + S2;
      }
    }

    for(int i=n-1;i>=1;i--){
      for(int j= i + 1;j<=n;j++){
        lli S = 0;
        for(int k=i;k<j;k++){
          S = max(S,a[i][k] + a[k+1][j]);
        }
        a[i][j] = S;
      }
    }

    cout << a[1][n] << "\n";
  }
  return 0;
}
