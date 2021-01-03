#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> Complete(n + 1,0);
  deque<int> rows;
  vector<pair<int,int>> ans;
  set<int> Set1,Set23;
  for(int i = 1;i<=n;i++){
    cin >> a[i];
    if(a[i] == 1){
      Set1.insert(i);
    }else if(a[i]){
      Set23.insert(i);
    }
    rows.push_back(i);
  }
  bool ok = true;
  for(int j=1;j<=n;j++){
    if(Complete[j])
      continue;
    if(a[j] == 1){
      Set1.erase(j);
      int r = rows.front();
      rows.pop_front();
      ans.push_back({r,j});
    }else if(a[j] == 2){
      Set23.erase(j);
      if(Set1.size()){
        int c = *Set1.begin();
        int r = rows.front();
        rows.pop_front();
        ans.push_back({r,j});
        ans.push_back({r,c});
        Set1.erase(c);
        Complete[c] = true;
      }else{
        ok = false;
        break;
      }
    }else if(a[j] == 3){
      Set23.erase(j);
      if(Set23.size()){
        int c = *Set23.begin();
        Set23.erase(c);
        int r = rows.front();
        rows.pop_front();
        ans.push_back({r,j});
        ans.push_back({r,c});
      }else if(Set1.size()){
        int c = *Set1.begin();
        Set1.erase(c);
        int r = rows.front();
        rows.pop_front();
        ans.push_back({r,j});
        ans.push_back({r,c});
      }else{
        ok = false;
        break;
      }
    }
  }
  if(!ok){
    cout << -1 << "\n";
  }else{
    cout << ans.size() << "\n";
    for(auto &x: ans){
      cout << x.first << " ";
      cout << x.second << "\n";
    }
  }

  return 0;
}
