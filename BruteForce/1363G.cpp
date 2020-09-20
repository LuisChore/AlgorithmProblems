#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases,n,m;
  cin >> cases;
  while(cases--){
    cin >> n;
    if(n<4){
      cout << -1 << "\n";
      continue;
    }
    deque<int> DQ;
    DQ.push_back(n-1);
    DQ.push_back(n-3);
    DQ.push_back(n);
    DQ.push_back(n-2);
    n-=4;
    m = n;
    for(int i=1;i<=n;i++){
      if(i&1)
        DQ.push_front(m);
      else
        DQ.push_back(m);
      m--;
    }
    for(auto &it : DQ){
      cout << it << " ";
    }
    cout << "\n";
  }
  return 0;
}
