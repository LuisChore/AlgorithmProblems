#include <bits/stdc++.h>
using namespace std;

long long int inf = 1e9;

double dp[2][101][30001];
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n+1),b(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i] >> b[i];
  }
  int offset = 100 * n;
  for(int i=0;i<=n;i++){
    for(int k=0;k<=n;k++){
      for(int sum = -100*n;sum<=200*n;sum++){
        if(!i){
          if(k)
            dp[i&1][k][sum + offset] = - inf;
          else
            dp[i&1][k][sum + offset] = 0;
          continue;
        }
        if(k){
          double opt1 = b[i];
          int ci = a[i] - b[i];
          int new_sum = 0;
          if(sum>=0){
            new_sum = sum + ci * 2;
          }else{
            if(abs(sum) >= 2*ci){
              opt1 += ci;
              new_sum = sum + 2*ci;
            }else{
              opt1 += abs(sum)/2.0;
              new_sum = 2*ci + sum;
            }
          }
          opt1 += dp[(i-1)&1][k-1][new_sum + offset];
          double opt2 = 0;
          new_sum = 0;
          if(sum<=0){
            new_sum = sum - b[i];
          }else{
            if(sum>=b[i]){
              opt2 += b[i]/2.0;
              new_sum = sum - b[i];
            }else{
              opt2 += sum/2.0;
              new_sum = sum - b[i];
            }
          }
          opt2 += dp[(i-1)&1][k][new_sum + offset];
          dp[i&1][k][sum + offset] = max(opt1,opt2);
          continue;
        }

        double opt = 0;
        int ci = a[i] - b[i];
        int new_sum = 0;
        if(sum<=0){
          new_sum = sum - b[i];
        }else{
          if(sum>=b[i]){
            opt += b[i]/2.0;
            new_sum = sum - b[i];
          }else{
            opt += sum/2.0;
            new_sum = sum - b[i];
          }
        }
        opt += dp[(i-1)&1][k][new_sum + offset];
        dp[i&1][k][sum + offset] = opt;
      }
    }
  }
  for(int k=1;k<=n;k++){
    cout << dp[n&1][k][offset] << " ";
  }
  cout << "\n";
  return 0;
}
