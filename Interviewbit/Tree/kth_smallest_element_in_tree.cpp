#include <iostream>



//Definition for binary tree
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void kthsmallest(TreeNode* A, int &B, int &ans){
  if(!A)
    return;
  kthsmallest(A->left,B,ans);
  if(B == 1){
    ans = A->val;
  }
  B--;
  kthsmallest(A->right,B,ans);
}
int kthsmallest(TreeNode* A, int B) {
  int ans = -1;
  kthsmallest(A,B,ans);
  return ans;
}


int main(){
  return 0;
}
