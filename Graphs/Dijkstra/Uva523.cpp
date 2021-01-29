#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

vector<int> get_numbers(string &s){
  char *p = strtok((char*)s.c_str()," ");
  vector<int> v;
  while(p){
    v.push_back(atol(p));
    p = strtok(NULL," ");
  }
  return v;
}
void process(vector<vector<pair<int,int>>> &adj,vector<int> &weights,int index){
  int n = adj.size();
  for(int i=0;i<n;i++){
    if(i != index && weights[i] != -1){
      adj[index].push_back({i,weights[i]});
    }
  }
}

void print_path(vector<int> &parent,int u){
  if(parent[u] == -1){
    cout << "Path: " << u + 1 ;
    return;
  }
  print_path(parent,parent[u]);
  cout << "-->" << u + 1 ;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  bool first = true;
  cin >> cases;
  cin.ignore(1, '\n');
  cin.ignore(1, '\n');
  while(cases--){
    string aux;
    getline(cin,aux);
    vector<int> v = get_numbers(aux);
    int n = v.size();
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    process(adj,v,0);
    for(int i=1;i<n;i++){
      getline(cin,aux);
      v = get_numbers(aux);
      process(adj,v,i);
    }
    // // print graph
    // for(int i=0;i<n;i++){
    //   cout << i << ":\n";
    //   for(auto &v: adj[i]){
    //     cout << "(" << v.first << "," << v.second << "),";
    //   }cout << "\n";
    // }
    getline(cin,aux);
    vector<int> costs = get_numbers(aux);

    while(getline(cin,aux) && aux.size() != 0){
        vector<int> q = get_numbers(aux);
        int source = q[0],dest = q[1];
        if(!first)
          cout << "\n";
        first = false;
        cout << "From "<< source << " to "<< dest << " :\n";
        source--;
        dest--;
        vector<int> parent(n,-1),dist(n,inf_int);
        dist[source] = 0;
        priority_queue<pair<int,int>> Q;
        Q.push({dist[source],source});
        while(Q.size()){
          pair<int,int> aux = Q.top();
          Q.pop();
          int u = aux.second;
          int d = -aux.first;
          if(d > dist[u])
            continue;
          for(auto &v: adj[u]){
            int cost = dist[u] + v.second + ( u != source ? costs[u] : 0 );
            if(dist[v.first] > cost){
              dist[v.first] = cost;
              parent[v.first] = u;
              Q.push({-dist[v.first],v.first});
            }
          }
        }
        print_path(parent,dest);
        cout << "\nTotal cost : " << dist[dest] << "\n";
    }
  }
  return 0;
}


/*
2

0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 3

0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 3

*/
