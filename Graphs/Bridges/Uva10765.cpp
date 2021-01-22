#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> art_point;
vector<int> disconnections;
vector<int> dfs_num,dfs_low;
vector<int> parent;
int root = -1,children;

void dfs(int u,int count = 0){
  dfs_num[u] = dfs_low[u] = count++;
  for(auto &v: adj[u]){
    if(dfs_num[v] == -1){
      if(u == root){
        children++;
      }
      parent[v] = u;
      dfs(v,count);
      if(dfs_low[v] >= dfs_num[u] && u != root){
        art_point[u] = true;
      }
      if(dfs_low[v] > dfs_num[u]){
        disconnections[u]++;
        disconnections[v]++;
      }
      dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }else if(parent[u] != v){
      dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
  }
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  while(cin >> n >> m){
    if(!n)
      break;
    adj.assign(n,vector<int>());
    dfs_num.assign(n,-1);
    disconnections.assign(n,0);
    dfs_low.assign(n,0);
    parent.assign(n,0);
    art_point.assign(n,false);
    int u,v;
    while(cin >> u >> v){
      if(u == -1)
        break;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
      if(dfs_num[i] == -1){
        root = i;
        children = 0;
        dfs(i);
        if(children>1){
          art_point[i] = true;
        }

      }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
      if(art_point[i]){
        if(disconnections[i] < adj[i].size())
          disconnections[i]++;
        ans.push_back({-disconnections[i],i});
      }else{
        ans.push_back({-1,i});
      }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<m;i++){
      cout << ans[i].second << " " << ans[i].first * -1 << "\n";
    }
    cout << "\n";
  }
  return 0;
}


/*
8 4
0  4
1  2
2  3
2  4
3  5
3  6
3  7
6  7
-1 -1
0  0
*/
