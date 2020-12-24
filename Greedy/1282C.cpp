#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    lli T,a,b;
    cin >> n >> T >> a >> b;
    lli ans = 0;
    vector<pair<int,int>> V(n);
    vector<int> A(n + 1,0);
    vector<int> B(n + 1,0);

    for(int i=0;i<n;i++){
      cin >> V[i].second;
      V[i].second = (V[i].second) ? b : a;
    }

    for(int i=0;i<n;i++)
      cin >> V[i].first;
    sort(V.begin(),V.end());

    for(int i=n-1;i>=0;i--){
      if(V[i].second == b){
        B[i]++;
      }else{
        A[i]++;
      }
      B[i] += B[i+1];
      A[i] += A[i+1];
    }
    int i = 0;
    lli t = 0;
    lli best_ans = 0;
    while(i<n){
      int sum = 1;
      lli z = V[i].first - 1 - t;
      lli x = A[i];
      lli y = B[i];
      lli u = min(z/a,x);
      z -= u*a;
      lli v = min(z/b,y);
      best_ans = max(best_ans,ans + v + u);
      t += V[i].second;
      i++;
      while(i<n && t<=T){
        if(V[i].first > t){
          break;
        }else{
          sum++;
          t += V[i].second;
          i++;
        }
      }
  //    cout << t << "-" << sum << "\n";
      if(t<=T){
        ans += sum;
      }else{
        break;
      }
    }
    cout << max(ans,best_ans) << "\n";
  }
}
