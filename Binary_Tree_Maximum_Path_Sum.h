/*Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.*/

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
    int maxPathSum(TreeNode* root) {
        int maxS=INT_MIN;
        maxPathSum(root, maxS);
        return maxS;
    }
private:
   int maxPathSum(TreeNode* root, int& maxSum) {
        if(root==NULL) return 0;
        int leftSide=maxPathSum(root->left, maxSum);
        int rightSide=maxPathSum(root->right, maxSum);
        int onePath=max(root->val, max(leftSide, rightSide)+root->val);
        maxSum=max(max(maxSum, onePath), root->val+leftSide+rightSide);
        return onePath;
    } 
};
