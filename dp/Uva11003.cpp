#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 3000;
vector<int> W,L;int n;
vector<vector<int>> memo;

int f(int n,int weight){
  if(n == 1)
    return weight <= L[n];

  if(memo[n][weight] != -1)
    return memo[n][weight];

  int opt1 = 0,opt2 = f(n-1,weight);
  if(weight <= L[n]){
    int new_weight = weight + W[n];
    if(new_weight > LIMIT)
      opt1 = 1;
    else
      opt1 = f(n-1,new_weight) + 1;
  }
  return memo[n][weight] = max(opt1,opt2);
}
int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  while(cin >> n && n){
    W.assign(n+1,0);
    L.assign(n+1,0);
    memo.assign(n+1,vector<int>(LIMIT + 10,-1));
    for(int i=1;i<=n;i++){
      cin >> W[i] >> L[i];
    }
    cout << f(n,0) << "\n";

  }
  return 0;
}
