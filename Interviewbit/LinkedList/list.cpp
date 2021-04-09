#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};


void push_front(ListNode* &A,int val){
  ListNode *temp = new ListNode(val);
  temp->next = A;
  A = temp;
}

void push_back(ListNode* &A,int val){
  if(A == NULL){
    A = new ListNode(val);
    return;
  }
  ListNode *aux = A;
  while(aux->next){
    aux = aux -> next;
  }
  aux->next = new ListNode(val);
}

void print_list(ListNode *A){
  ListNode *aux = A;
  while(aux){
    cout << aux -> val;
    if(aux->next)
      cout << "->";
    aux = aux->next;
  }
  cout << "\n";
}

int main(){
  ListNode *l = NULL;
  push_back(l,3);
  push_back(l,3);
  push_back(l,4);
  push_front(l,2);
  push_front(l,1);
  push_front(l,1);
  push_back(l,6);
  push_back(l,6);
  print_list(l);

  return 0;
}
