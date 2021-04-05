#include <iostream>
#include <stack>
using namespace std;


bool is_operator(char &c){
  return (c == '+' || c == '-' || c == '/' || c == '*');
}

int braces(string A) {
  stack<char> S;
  for(auto &c: A){
    if(c == '(' || is_operator(c))
      S.push(c);
    else if(c == ')'){
      bool ok = false;
      while(S.top() != '('){
        S.pop();
        ok = true;
      }
      S.pop();
      if(!ok)
        return 1;
    }
  }
  return 0;
}


int main(){
  string A = "(a)";
  cout << braces(A) << "\n";
  return 0;
}
