#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> grid;
vector<vector<int>> memo;
int row,col;


int f(int i,int j){
  if( j == col){
    return grid[i][j];
  }

  if(memo[i][j] != -1){
    return dp[i][j];
  }
  memo[i][j] = 1;
  vector<pair<int,int>> options(3);
  options[0].first = (i == 1) ? row : (i-1);
  options[1].first =(i == row) ? 1: (i+1);
  options[2].first = i;

  options[0].second = f(options[0].first,j+1) + grid[i][j];
  options[1].second = f(options[1].first,j+1) + grid[i][j];
  options[2].second = f(options[2].first,j+1) + grid[i][j];
  sort(options.begin(),options.end());
  if(options[0].second<=options[1].second && options[0].second<=options[2].second){
    return dp[i][j] = options[0].second;
  }else if(options[1].second<=options[0].second && options[1].second<=options[2].second){
    return dp[i][j] = options[1].second;
  }else{
    return dp[i][j] = options[2].second;
  }
}

void rec(int i,int j){
  if( j == col){
    cout << i << "\n";
    return;
  }
  vector<pair<int,int>> options(3);
  options[0].first = (i == 1) ? row : (i-1);
  options[1].first =(i == row) ? 1: (i+1);
  options[2].first = i;

  options[0].second = f(options[0].first,j+1) + grid[i][j];
  options[1].second = f(options[1].first,j+1) + grid[i][j];
  options[2].second = f(options[2].first,j+1) + grid[i][j];
  sort(options.begin(),options.end());
  cout << i << " ";
  if(options[0].second == dp[i][j]){
    rec(options[0].first,j+1);
  }else if(options[1].second<=options[0].second && options[1].second<=options[2].second){
    rec(options[1].first,j+1);
  }else{
    rec(options[2].first,j+1);
  }
}

int main(){
  cin.sync_with_stdio(0);cin.tie(0);
  dp.assign(15,vector<int>(105,0));
  grid.assign(15,vector<int>(105,0));
  memo.assign(15,vector<int>(105,0));
  while(cin >> row >> col){
    for(int i=1;i<=row;i++)
      for(int j=1;j<=col;j++){
        memo[i][j] = -1;
        cin >> grid[i][j];
      }
    int mini = f(1,1);
    for(int i=1;i<=row;i++){
      mini = min(mini,f(i,1));
    }

    for(int i=1;i<=row;i++){
      if(f(i,1) == mini){
        rec(i,1);
        break;
      }
    }
    cout << mini << "\n";
  }
  return 0;
}
