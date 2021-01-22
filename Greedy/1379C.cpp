#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    lli n,m;
    cin >> n >> m;
    vector<pair<lli,lli>> P(m);
    vector<lli> acum(m);
    for(int i=0;i<m;i++){
      cin >> P[i].first;
      cin >> P[i].second;
    }
    sort(P.begin(),P.end());
    reverse(P.begin(),P.end());
    for(int i=0;i<m;i++){
      acum[i] = P[i].first;
      if(i)
        acum[i]+=acum[i-1];
    }
    lli best = 0;
    if(m>=n)
      best = acum[n-1];
    for(int i=0;i<m;i++){
      int low=0,high = m-1,aux = m;
      while(low<=high){
        int mid = (low + high)>>1;
        if(P[mid].first <= P[i].second){
          aux = mid;
          high = mid - 1;
        }else{
          low = mid + 1;
        }
      }

      int t = aux + 1;
      lli sum = 0;
      if(aux)
        sum += acum[aux-1];
      if(P[i].first > P[i].second){
        t--;
      }else{
        sum += P[i].first;
      }
      int need = n - t;
      if(need>=0){
        sum += need * P[i].second;
        best = max(best,sum);
      }
    }
    cout << best << "\n";
  }
  return 0;
}
