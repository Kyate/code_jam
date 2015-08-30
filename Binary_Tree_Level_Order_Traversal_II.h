/*****************************************************************************
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*********************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
               queue<TreeNode*> myqueue;
       vector<vector<int>> result;
       if(root == NULL) return result;
       TreeNode* node = root;
       myqueue.push(node);
       while(!myqueue.empty())
       {
           vector<int>ans;
           int n = myqueue.size();
           for(int i = 0;i<n;i++)
           {
               node = myqueue.front();
               myqueue.pop();
               ans.push_back(node->val);
                    
               if(node->left){
                   myqueue.push(node->left);
               }
               
               if(node->right){ 
                   myqueue.push(node->right);
               }
           }
           result.push_back(ans); //push each level nodes into result.
       }
      reverse(result.begin(),result.end());
      return result;
    }
};
