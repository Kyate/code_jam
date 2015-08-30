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
    void recoverTree(TreeNode* root) {

    if(root == NULL)
        return;
    TreeNode* node1 = NULL, *node2 = NULL, *previous = NULL;

    traverse(root, previous, node1, node2);
    if(node1!=NULL && node2!=NULL)
    {
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
}

void traverse(TreeNode* root, TreeNode* & previous, TreeNode* & node1, TreeNode* & node2)
{
    if(root == NULL)
        return;

    traverse(root->left, previous, node1, node2);
    int val = root->val;

    if(previous != NULL)
    {
        if( previous->val > root->val )
        {
            if(node1 == NULL)
            {
                node1 = previous;
                node2 = root;
            }
            else
                node2 = root;
        }
    }
    previous = root;
    traverse(root->right, previous, node1, node2);
}
};
