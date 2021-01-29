#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};

bool contains(string &s,char c){
  for(auto &si: s)
    if(si == c)
      return true;
  return false;
}

bool can(int i,int j,int n,int m){
  if(i>=0 && i<n && j>=0 && j<m)
    return true;
  return false;
}

string get_value(string &s,int rot){
  string ans = "";
  for(int i=4-rot;i<4;i++)
    ans += s[i];

  for(int i=0;i<4-rot;i++)
    ans += s[i];

  return ans;
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  while(cin >> n >> m){
    string aux;
    vector<vector<string>> grid(n,vector<string>(m,""));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i == n-1 && j == m-1)
          continue;
        cin >> aux;
        grid[i][j] = "";
        grid[i][j] += contains(aux,'N') ? '1' : '0';
        grid[i][j] += contains(aux,'E') ? '1' : '0';
        grid[i][j] += contains(aux,'S') ? '1' : '0';
        grid[i][j] += contains(aux,'W') ? '1' : '0';
      }
    }
    vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(4,inf_int)));
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    dist[0][0][0] = 0;
    while(Q.size()){
      tuple<int,int,int> u = Q.front();
      Q.pop();
      int i = get<0>(u);
      int j = get<1>(u);
      int rot = get<2>(u);
      if(i == n-1 && j == m - 1)
        continue;
      string aux = get_value(grid[i][j],rot);
      for(int r=0;r<4;r++){
        int I = i + row[r];
        int J = j + col[r];
        if(!can(I,J,n,m) || aux[r] == '0')
          continue;
        int new_rot = (rot + 1) % 4;
        if(dist[I][J][new_rot] == inf_int){
          dist[I][J][new_rot] = 1 + dist[i][j][rot];
          Q.push({I,J,new_rot});
        }
      }
    }
    int ans = inf_int;
    for(int r=0;r<4;r++){
      ans = min(ans,dist[n-1][m-1][r]);
    }
    if(ans == inf_int)
      cout << "no path to exit\n";
    else
      cout << ans << "\n";

  }
  return 0;
}

/*
2 2
NES
S
WS
3 2
NSWE
SW
SEW
NEW
SN
*/
