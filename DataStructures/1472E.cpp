#include <bits/stdc++.h>
using namespace std;


int find_sol(vector<pair<pair<int,int>,int>> &orderv,vector<int> &mini,
  pair<int,int> p){
    int low = 0,high = orderv.size()-1,ans = orderv.size();
    while(low<=high){
      int mid = (low + high) >> 1;
      if(orderv[mid].first.first < p.first){
        ans = mid;
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    if(ans == orderv.size())
      return -1;

    int second_index = mini[ans];
    if(orderv[second_index].first.second < p.second){
      return orderv[second_index].second;
    }
    return -1;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<pair<pair<int,int>,int>> orderv(n);
    vector<int> mini(n);
    for(int i=0;i<n;i++){
      cin >> v[i].first;
      cin >> v[i].second;
      orderv[i].first = v[i];
      orderv[i].second = i + 1;
    }
    sort(orderv.begin(),orderv.end());
    mini[0] = 0;
    int min_value = orderv[0].first.second;
    for(int i=1;i<n;i++){
      int aux = orderv[i].first.second;
      if(aux < min_value){
        mini[i] = i;
        min_value = aux;
      }else{
        mini[i] = mini[i-1];
      }
    }

    for(int i=0;i<n;i++){
      int index = find_sol(orderv,mini,v[i]);
      if(index != -1 ){
        cout << index << " ";
      }else{
        swap(v[i].first,v[i].second);
        index = find_sol(orderv,mini,v[i]);
        cout << index << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
