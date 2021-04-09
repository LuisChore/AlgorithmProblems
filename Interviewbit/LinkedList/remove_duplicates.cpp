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

ListNode* deleteDuplicates(ListNode* A) {
  if(A == NULL)
    return A;
  ListNode *ans = NULL,*aux_ans = NULL;
  int value = A->val;
  ListNode *aux = A->next;
  int freq = 1;
  while(aux){
    if(aux->val == value){
      aux = aux->next;
      freq++;
    }else{
      if(freq == 1){
        if(ans == NULL){
          ans = new ListNode(value);
          aux_ans = ans;
        }else{
          aux_ans->next = new ListNode(value);
          aux_ans = aux_ans->next;
        }
      }
      value = aux->val;
      freq = 1;
      aux = aux->next;
    }
  }

  if(freq == 1){
    if(ans == NULL)
      ans = new ListNode(value);
    else
      aux_ans -> next = new ListNode(value);
  }
  return ans;
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
  ListNode *ans = deleteDuplicates(l);
  print_list(ans);
  return 0;
}
