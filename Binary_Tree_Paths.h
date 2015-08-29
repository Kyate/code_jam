/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

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
    vector<string> binaryTreePaths(TreeNode* root) {
       if(root == NULL) return result;
       binaryTreePaths_helper(root, "");
       return result;
    }
    
    void binaryTreePaths_helper(TreeNode* root, string ans)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
           ans = ans + to_string(root->val);
           result.push_back(ans);
        }
        else
           ans = ans + to_string(root->val) + "->";
        
        binaryTreePaths_helper(root->left,  ans);
        binaryTreePaths_helper(root->right,  ans);
    }
    
private:
vector<string> result;
};
