#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
  vector<int> parent,rank;
  int sets;
  UnionFind(int n){
    sets = n;
    parent.assign(n,0);
    rank.assign(n,0);
    for(int i=0;i<n;i++){
      parent[i] = i;
    }
  }

  int find(int u){
    if(parent[u] == u)
      return u;
    parent[u] = find(parent[u]);
    return parent[u];
  }

  void union_set(int u,int v){
    int idU = find(u);
    int idV = find(v);
    sets--;
    if(idU == idV)
      return;
    if(rank[idU] > rank[idV]){
      parent[idV] = idU;
    }else{
      parent[idU] = idV;
      if(rank[idU] == rank[idV])
        rank[idV]++;
    }
  }
};

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n,m;
    cin >> n >> m;
    int ans = m,cycles = 0;
    UnionFind ds(n);
    for(int i=0;i<m;i++){
      int x,c;
      int index = n + i;
      cin >> x >> c;
      x--;
      c--;
      if(x == c){
        cycles--;
        continue;
      }
      if(ds.find(x) == ds.find(c))
        cycles++;
      ds.union_set(x,c);
    }
    cout << ans + cycles << "\n";
  }
  return 0;
}
