#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* create_tree(vector<int> &A,int l,int r){
  if(l>r)
    return NULL;
  if(l == r)
    return new TreeNode(A[l]);

  int index = l,max_value = A[l];
  for(int i=l;i<=r;i++){
    if(A[i] > max_value){
      index = i;
      max_value = A[i];
    }
  }
  TreeNode *node = new TreeNode(max_value);
  node->left = create_tree(A,l,index-1);
  node->right = create_tree(A,index + 1,r);
  return node;
}


TreeNode* buildTree(vector<int> &A) {
  return create_tree(A,0,A.size()-1);
}


int main(){
  vector<int> A = {1,2,3};
  TreeNode *ans = buildTree(A);
}
