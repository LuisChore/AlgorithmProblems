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
    cin >> n;
    vector<int> a(2*n);
    map<int,int> Map;
    for(int i=0;i<2*n;i++){
      cin >> a[i];
      Map[a[i]]++;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int index = -1;
    Map[a[0]]--;
    for(int i=1;i<2*n;i++){
      int x = a[i] + a[0];
      int temp = a[0];
      Map[a[i]]--;
      bool ok = true;
      for(int j=1;j<2*n;j++){
        if(Map[a[j]] > 0 ){
          Map[a[j]]--;
          int comp = temp - a[j];
          if(Map.count(comp) && Map[comp]>0){
            temp = a[j];
            Map[comp]--;
          }else{
            ok = false;
            break;
          }
        }
      }
      Map.clear();
      for(int j=1;j<2*n;j++){
        Map[a[j]]++;
      }
      if(ok){
        index = i;
        break;
      }
    }
    if(index == -1){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int x = a[index] + a[0];
    cout << x << "\n";
    cout << a[index] << " " << a[0] << "\n";
    int temp = a[0];
    Map[a[index]]--;
    bool ok = true;
    for(int j=1;j<2*n;j++){
      if(Map[a[j]] > 0 ){
        Map[a[j]]--;
        int comp = temp - a[j];
        cout << a[j] << " " << comp << "\n";
        temp = a[j];
        Map[comp]--;
      }
    }
  }

  return 0;
}
