#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m,cases = 1;
  while(cin >> n >> m){
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
      int u,v,w;
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    vector<vector<int>> dist(n,vector<int>(2,inf_int));
    dist[0][1] = 0;
    priority_queue<pair<int,pair<int,int>>> Q;
    Q.push({0,{0,1}});
    while(Q.size()){
      pair<int,pair<int,int>> aux = Q.top();
      Q.pop();
      int d = - aux.first;
      pair<int,int> u = aux.second;
      if(dist[u.first][u.second] < d)
        continue;
      for(auto &v: adj[u.first]){
        int cost = dist[u.first][u.second] + v.second;
        if(cost < dist[v.first][1-u.second]){
          dist[v.first][1-u.second] = cost;
          Q.push({-cost,{v.first,1-u.second}});
        }
      }
    }
    cout << "Set #" << cases++ << "\n";
    if(dist[n-1][1] != inf_int){
      cout << dist[n-1][1] << "\n";
    }else{
      cout << "?\n";
    }
  }
  return 0;
}
/*
3 3
0 1 10
0 2 10
1 2 10
4 4
0 1 10
0 2 10
1 2 10
2 3 10
*/
