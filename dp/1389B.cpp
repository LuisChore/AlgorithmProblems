#include <iostream>
using namespace std;
typedef long long lli;
int n,k,z;
int memo[100010][10];
int v[100010];

int f(int i,int l){
  if(i + 2*l == k)
    return v[i];
  if(memo[i][l] != -1)
    return memo[i][l];
  if(i == 0)
    return memo[i][l] = v[i] + f(i+1,l);
  int opt1 = 0,opt2 = 0;
  if(l < z && (i + (l + 1) * 2) <=k)
    opt1 = v[i - 1] + v[i] + f(i,l + 1);
  else if(l < z)
    opt1 = v[i] + v[i-1];
  opt2 = v[i] + f(i+1,l);
  return memo[i][l] = max(opt1,opt2);
}
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n >> k >> z;
    for(int i = 0;i<n;i++){
      cin >> v[i];
      for(int j=0;j<=z;j++){
        memo[i][j] = -1;
      }
    }
    cout << f(0,0) << "\n";
  }
  return 0;
}
