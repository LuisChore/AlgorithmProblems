#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
string s,t;
lli dp[201][201][201];
bool memo[201][201][201];

lli f(int index,int k,int numt1){
  if(!index)
    return 0;

  if(memo[index][k][numt1])
    return dp[index][k][numt1];

  memo[index][k][numt1] = true;

  if(k){
    lli opt1 = (t[1] == t[0]) ? numt1 : 0;
    opt1 += f(index-1,k-1,numt1 + 1);

    lli opt2 = numt1;
    opt2 += f(index-1,k-1,numt1 + (t[0] == t[1]));

    lli opt3 = 0;
    if(t[1] == s[index]){
      opt3 = (t[1] == t[0]) ? numt1 : 0;
      opt3 += f(index-1,k,numt1 + 1);
    }else if(t[0] == s[index]){
      opt3 = numt1;
      opt3 += f(index-1,k,numt1);
    }else{
      opt3 = f(index-1,k,numt1);
    }
    lli maxi = max(opt1,max(opt2,opt3));
    return dp[index][k][numt1] = maxi;
  }else{
    lli opt3 = 0;
    if(t[1] == s[index]){
      opt3 = (t[1] == t[0]) ? numt1 : 0;
      opt3 += f(index-1,k,numt1 + 1);
    }else if(t[0] == s[index]){
      opt3 = numt1;
      opt3 += f(index-1,k,numt1);
    }else{
      opt3 = f(index-1,k,numt1);
    }
    return dp[index][k][numt1] = opt3;
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  cin >> s >> t;
  s = "$" + s;
  cout << f(n,k,0) << "\n";
  return 0;
}
