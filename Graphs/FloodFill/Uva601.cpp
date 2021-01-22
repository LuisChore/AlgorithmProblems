#include <bits/stdc++.h>
using namespace std;

int r[4] = {-1,0,1,0};
int c[4] = {0,1,0,-1};

vector<vector<int>> grid;
string s[85];
int n;

void floodfill(int i,int j, char ch,int t,bool &found){
  if(i<0 || j<0 || i>=n || j>=n)
    return;
  if(s[i][j] != ch || grid[i][j] != -1)
    return;
  grid[i][j] = t;
  if( ch == 'W' && j == n-1)
    found = true;

  if( ch == 'B' && i == n-1)
    found = true;

  for(int k=0;k<4;k++){
    int I = i + r[k];
    int J = j + c[k];
    floodfill(I,J,ch,t,found);
  }
}


bool can(int i,int j,int target){
  if(i<0 || j<0 || i>=n || j>=n)
    return false;
  return grid[i][j] == target;
}

void find_other(int i,int j, char ch,int t,int t2,bool &found){
  if(i<0 || j<0 || i>=n || j>=n)
    return;
  if(s[i][j] == 'U'){
    if(ch == 'W' && j == 0){
      found = true;
      return;
    }else if(ch == 'B' && i == 0){
      found = true;
      return;
    }
    for(int k=0;k<4;k++){
      int I = i + r[k];
      int J = j + c[k];
      if(can(I,J,t2)){
        found = true;
        return;
      }
    }
    return;
  }
  if(s[i][j] != ch || grid[i][j] != -1)
    return;
  grid[i][j] = t;
  for(int k=0;k<4;k++){
    int I = i + r[k];
    int J = j + c[k];
    find_other(I,J,ch,t,t2,found);
  }
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  while(cin >> n && n){
    grid.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
      cin >> s[i];
    bool over = false;
    for(int i=0;i<n;i++){
      if(s[i][0] == 'W'){
        bool found = false;
        floodfill(i,0,'W',0,found);
        if(found){
          cout << "White has a winning path.\n";
          over = true;
          break;
        }
      }
      if(s[0][i] == 'B'){
        bool found = false;
        floodfill(0,i,'B',2,found);
        if(found){
          cout << "Black has a winning path.\n";
          over = true;
          break;
        }
      }
    }
    if(over){
      continue;
    }
    // whites
    for(int i=0;i<n;i++){
      if(s[i][n-1] == 'W' || s[i][n-1] == 'U'){
        bool found = false;
        find_other(i,n-1,'W',1,0,found);
        if(found){
          cout << "White can win in one move.\n";
          over = true;
          break;
        }
      }
    }
    if(over)
      continue;
    // blacks
    for(int i=0;i<n;i++){
      if(s[n-1][i] == 'B' || s[n-1][i] == 'U'){
        bool found = false;
        find_other(n-1,i,'B',3,2,found);
        if(found){
          cout << "Black can win in one move.\n";
          over = true;
          break;
        }
      }
    }

    if(over)
      continue;

    cout << "There is no winning path.\n";
  }
  return 0;
}

/*
7

WBBUUUU
WWBUWWW
UWBBBWB
BWBBWWB
BWWBWBB
UBWWWBU
UWBBBWW

3

WBB
WWU
WBB

0
*/
