#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

int row[8]={-1,-1,0,1,1,1,0,-1};
int col[8]={0,1,1,1,0,-1,-1,-1};

bool can(int i,int j,int n,int m){
  if(i>=0 && i<n && j>=0 && j<m)
    return true;
  return false;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  vector<string> grid(n);
  for(int i=0;i<n;i++){
    cin >> grid[i];
  }

  int q;
  cin >> q;
  while(q--){
    int si,sj,di,dj;
    cin >> si >> sj;
    cin >> di >> dj;
    si--;
    sj--;
    di--;
    dj--;
    vector<vector<int>> dist(n,vector<int>(m,inf_int));
    deque<pair<int,int>> Q;
    Q.push_back({si,sj});
    dist[si][sj] = 0;
    while(Q.size()){
      pair<int,int> u = Q.front();
      Q.pop_front();
      if(u.first == di && u.second == dj)
        break;
      for(int r = 0;r<8;r++){
        int I = u.first + row[r];
        int J = u.second + col[r];
        if(!can(I,J,n,m))
          continue;
        int cost = ((grid[u.first][u.second] - '0') == r) ? 0 : 1;
        int new_cost = cost + dist[u.first][u.second];
        if(new_cost<dist[I][J]){
          dist[I][J] = new_cost;
          if(cost){
            Q.push_back({I,J});
          }else{
            Q.push_front({I,J});
          }
        }
      }
    }
    cout << dist[di][dj] << "\n";
  }

  return 0;
}
/*
5 5
04125
03355
64734
72377
02062
3
4 2 4 2
4 5 1 4
5 3 3 4
*/
