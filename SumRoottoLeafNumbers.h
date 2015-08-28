/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.*/

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
   int sumNumbers(TreeNode* root) {
 
        stack<TreeNode*> nodes;
        if (!root)
         return 0;

        int total = 0;
        int current = 0;
        TreeNode* last = nullptr;
        while (root || !nodes.empty())
        {
            if (root)
            {
                nodes.push(root);
                current *= 10;
                current += root->val;
                root = root->left;
            }
            else 
            {
                root = nodes.top();
                if (root->right && root->right != last)
                {
                    root = root->right;
                }
                else 
                {
                     nodes.pop();
                     last = root;
                     // only add sum of leaf node
                     if (root->right == NULL && root->left == NULL)
                        total += current;
                     current /= 10;
                     root = NULL;
                }
            }
          }

         return total;
   }
 };
 /*class Solution {
public:
   int sumNumbers(TreeNode* root) {
        total = 0;
        helper(root, 0);
        return total;
    }
        
private:
    void helper(TreeNode*root, int sum) {
        if (root == NULL) return;

        sum = sum * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            total += sum;
            return;
        }

        helper(root->left, sum);
        helper(root->right, sum);
    }
int total;
};*/
