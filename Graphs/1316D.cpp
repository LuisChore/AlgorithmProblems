#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lli;
const lli inf = 1e18;

typedef tree<
lli,
null_type,//mapped key
less<lli>,//comp
rb_tree_tag,
tree_order_statistics_node_update
>ordered_set;

int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};

int n;
bool can(int i,int j){
  if(i>=0 && i<n && j>=0 && j<n)
    return true;
  return false;
}
char get_parent(int i,int j,int I,int J){
  if(I > i)
    return 'D';
  if(I < i)
    return 'U';
  if(J > j)
    return 'R';
  if(J < j)
    return 'L';
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<vector<pair<int,int>>> S(n);
  vector<string> grid(n);
  for(int i=0;i<n;i++){
    for(int j= 0;j<n;j++){
      grid[i] += '.';
      S[i].push_back({-1,-1});
      cin >> S[i][j].first;
      cin >> S[i][j].second;
    }
  }
  bool valid = true;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(grid[i][j] != '.'){
        continue;
      }
      if(S[i][j].first == -1){
        // next
        queue<pair<int,int>> Q;
        Q.push({i,j});
        int I = -1,J = -1;
        bool ok = false;
        for(int r = 0;r<4;r++){
          I = i + row[r];
          J = j + col[r];
          if(can(I,J) && grid[I][J] == '.' && S[I][J].first == -1){
            ok = true;
            break;
          }
        }
        if(!ok){
          valid = false;
          break;
        }
        Q.push({I,J});
        grid[i][j] = get_parent(i,j,I,J);
        grid[I][J] = get_parent(I,J,i,j);
        while(Q.size()){
          pair<int,int> u = Q.front();
          Q.pop();
          int ui = u.first;
          int uj = u.second;
          for(int r = 0;r<4;r++){
            int vi = ui + row[r];
            int vj = uj + col[r];
            if(can(vi,vj) && grid[vi][vj] == '.' && S[vi][vj].first == -1){
              grid[vi][vj] = get_parent(vi,vj,ui,uj);
              Q.push({vi,vj});
            }
          }
        }
        continue;
      }

      if(S[i][j].first == (i + 1) && S[i][j].second == (j+1)){
        queue<pair<int,int>> Q;
        grid[i][j] = 'X';
        Q.push({i,j});
        while(Q.size()){
          pair<int,int> u = Q.front();
          Q.pop();
          int ui = u.first;
          int uj = u.second;
          for(int r = 0;r<4;r++){
            int vi = ui + row[r];
            int vj = uj + col[r];
            if(can(vi,vj) && grid[vi][vj] == '.' &&
             S[vi][vj].first == S[ui][uj].first &&
             S[vi][vj].second == S[ui][uj].second){
              grid[vi][vj] = get_parent(vi,vj,ui,uj);
              Q.push({vi,vj});
            }
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(grid[i][j] == '.'){
        valid = false;
        break;
      }
    }
  }
  if(!valid){
    cout << "INVALID\n";
   return 0;
  }
  cout << "VALID\n";
  for(int i=0;i<n;i++){
    cout << grid[i] << "\n";
  }

  return 0;
}
