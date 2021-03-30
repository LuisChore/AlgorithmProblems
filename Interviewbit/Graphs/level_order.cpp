#include <queue>
#include <iostream>
using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* A) {
  queue<pair<TreeNode*,int>> Q;
  vector<vector<int>> ans;
  Q.push({A,0});
  while(Q.size()){
    pair<TreeNode*,int> node = Q.front();
    Q.pop();
    if(node.second + 1 > ans.size())
      ans.push_back(vector<int>());
    ans[node.second].push_back(node.first->val);
    if(node.first->left)
      Q.push({node.first->left,node.second + 1});
    if(node.first->right)
      Q.push({node.first->right,node.second + 1});
  }
  return ans;
}

int main(){
  return 0;
}
