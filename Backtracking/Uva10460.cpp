#include <bits/stdc++.h>
using namespace std;


string add(string &s, char c,int pos){
  string t = "";
  for(int i=0;i<s.size();i++){
    if(i == pos){
      t += c;
    }
    t += s[i];
  }
  if( pos == s.size())
    t += c;
  return t;
}

vector<long long> fact;
void solve(long long sum,long long t,string &s){

  string ans = "";
  ans += s[0];
  long long x = 2;
  int index = 1;
  long long value = (t < 20) ? fact[t] : -1;
  long original_t = t;
  while(ans.size() < s.size()){
    if(t > 15){
      ans = add(ans,s[index],0);
    }else if(t == 15){
      value = 1LL;
      for(long long i=original_t;i>x;i--){
        value = value * i;
      }
      long long pos = (sum - 1) / value;
      ans = add(ans,s[index],pos);
      sum = sum - pos * value;
    }else{
      long long seg_size = value / x;
      long long pos = (sum - 1) / seg_size;
      ans = add(ans,s[index],pos);
      sum = sum - pos*seg_size;
      value  = seg_size;
    }
    x++;
    index++;
    t--;
  }
  cout << ans << "\n";

}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int cases;
  string s;
  long long t;
  fact.push_back(1);
  for(long long i=1; i <= 20; i++){
    fact.push_back(fact[i-1] * i);
  }

  cin >> cases;
  while(cases--){
    cin >> s;
    cin >> t;
    solve(t,s.size(),s);
  }
  return 0;
}
/**
4
ACB
2
ABC
1
ABC
6
ABCD
12

*/
