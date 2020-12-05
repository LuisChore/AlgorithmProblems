#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

string s,t;

int get_first(vector<int> &c){
  if(c[2] == 1){
    return (1 - (s[c[0]] - '0'));
  }else{
    return (s[c[0]] - '0');
  }
}

int get_last(vector<int> &c){
  if(c[2] == 1){
    return (1 - (s[c[1]] - '0'));
  }else{
    return (s[c[1]] - '0');
  }
}


void Left(vector<int> &c){
  if(c[0] <= c[1]){
    c[1]--;
  }else{
    c[1]++;
  }
}

int Right(vector<int> &c){
  if(c[0] <= c[1]){
    c[0]++;
  }else{
    c[0]--;
  }
}

void change(vector<int> &c){
  swap(c[0],c[1]);
  c[2] = 1 - c[2];
}


int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases,n;
  cin >> cases;
  while(cases--){
    cin >> n >> s >> t;
    vector<int> ans;
    vector<int> curr = {0,n-1,0};
    int m = n-1;
    while(m>=0){
      if(get_last(curr) == (t[m] - '0') ){
        Left(curr);
        m--;
      }else if(get_first(curr) == get_last(curr)){
        ans.push_back(m+1);
        change(curr);
        Left(curr);
        m--;
      }else{
        ans.push_back(1);
        Right(curr);
        change(curr);
        ans.push_back(m+1);
        m--;
      }
    }
    cout << ans.size();
    for(int i=0;i<ans.size();i++){
      cout << " " << ans[i];
    }
    cout << "\n";
  }

}
