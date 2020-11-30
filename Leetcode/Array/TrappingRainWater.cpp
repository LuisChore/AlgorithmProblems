#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
  int n = height.size();
  vector<int> next_geq(n,-1);
  vector<int> g(n,n-1);
  vector<int> acum(n,0);
  stack<int> S;
  for(int i=n-2;i>=0;i--){
    if(height[i] > height[g[i+1]]){
      g[i] = i;
    }else{
      g[i] = g[i+1];
    }
  }
  for(int i=0;i<n;i++){
    while(S.size() && height[i] >= height[S.top()]){
      next_geq[S.top()] = i;
      S.pop();
    }
    S.push(i);
  }

  for(int i=0;i<n;i++){
    acum[i] = height[i];
    if(i)
      acum[i]+=acum[i-1];
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    if(next_geq[i] == -1)
      continue;

    int u = next_geq[i];
    if(i && next_geq[i-1] == -1){
      u = g[i];
      int sum = acum[u-1] - acum[i-1];
      int area = (u-i) * height[u];
      ans += area - sum;
    }else{
      int sum = acum[u-1] - acum[i];
      int area = (u-i-1) * height[i];
      ans += area - sum;
    }
    i = u - 1;
  }
  return ans;

}

int main(){
  vector<int> v = {0,7,1,4,6};
  cout << trap(v) << "\n";
  return 0;
}
