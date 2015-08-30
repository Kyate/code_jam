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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode*> myqueue;
       vector<vector<int>> result;
       if(root == NULL) return result;
       TreeNode* node = root;
       myqueue.push(node);
     
       int h = 0;
       while(!myqueue.empty())
       {
           vector<int>ans;
           int count = 0;
           int N = myqueue.size();
           for(int i = 0;i<N;i++)
           {
               node = myqueue.front();
               myqueue.pop();
               ans.push_back(node->val);
                    
               if(node->left) myqueue.push(node->left);
               if(node->right) myqueue.push(node->right);
           }
           
           if(h%2==1) //only odd leve, we change the order.
                reverse(ans.begin(),ans.end());
           result.push_back(ans); //push each level nodes into result.
           h= h+1; //go to next level
          
       }
       return result;
    }
};
