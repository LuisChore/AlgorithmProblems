#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n,k;
    cin >> n >> k;
    vector<int> arr(2*k + 1,0);
    vector<int> Map(2*k + 1,0);
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }

    for(int i=0;i<n/2;i++){
      int a = min(v[i],v[n-1-i]);
      int b = max(v[i],v[n-1-i]);
      int m = a + 1;
      int M = b + k;
      if(M < 2*k){
        arr[2*k] += 2;
        arr[M] += - 2;
      }
      arr[M] += 1;
      arr[m-1] += -1;
      arr[m-1] += 2;
      int s = v[i] + v[n-1-i];
      Map[s]++;
    }
    int ans = arr[2*k] - Map[2*k];
    for(int i=2*k-1;i>=2;i--){
      arr[i] = arr[i] + arr[i+1];
      int temp = arr[i] - Map[i];
      ans = min(ans,temp);
    }
    cout << ans << "\n";

  }
  return 0;
}
