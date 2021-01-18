#include <bits/stdc++.h>
using namespace std;

bool ishov(int i,vector<int> &v){
  if(i == 0 ||  i == (v.size() - 1))
    return false;

  if(v[i-1] < v[i] && v[i] > v[i+1])
    return true;
  if(v[i-1] > v[i] && v[i] < v[i+1])
    return true;
  return false;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  while(cases--){
    int n,ans,total = 0;
    cin >> n;
    vector<int> v(n);
    vector<bool> hov(n,false);
    for(int i=0;i<n;i++)
      cin >> v[i];

    for(int i=0;i<n;i++){
      if(i && i<n-1){
        if(v[i-1] < v[i] && v[i] > v[i+1]){
          hov[i] = true;
          total++;
        }else if(v[i-1] > v[i] && v[i] < v[i+1]){
          hov[i] = true;
          total++;
        }
      }
    }

    ans = total;
    for(int i=1;i<n-1;i++){
      int temp = v[i];
      // option 1
      int sub = 0;
      v[i] = v[i-1];
      if(hov[i])
        sub++;
      if(hov[i-1])
        sub++;
      if(ishov(i+1,v))
        sub = sub + (hov[i+1]? 0 : -1);
      else
        sub = sub + (hov[i+1]? 1 : 0);

      ans = min(ans, total - sub);

      // option 2
      sub = 0;
      v[i] = v[i+1];
      if(hov[i])
        sub++;
      if(hov[i+1])
        sub++;
      if(ishov(i-1,v))
        sub = sub + (hov[i-1]? 0 : -1);
      else
        sub = sub + (hov[i-1]? 1 : 0);
      ans = min(ans, total - sub);


      v[i] = temp;
    }

    if(n>1){
      if(hov[1]){
        ans = min(ans,total - 1);
      }else if(hov[n-1]){
        ans = min(ans,total - 1);
      }
    }

    cout << ans << "\n";

  }
  return 0;
}
