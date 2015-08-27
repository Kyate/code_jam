
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child 
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mystack;
        if(root == NULL) return result;
        if(root->right!=NULL)
            mystack.push(root->right);
        mystack.push(root);
        root = root->left;
        while(!mystack.empty()){
                /**************************************
                Do following while root is not NULL
                a) Push root's right child and then root to stack.
                b) Set root as root's left child.
                **************************************/
               while(root)
               {
                   if(root->right!=NULL)
                      mystack.push(root->right);
                    mystack.push(root);
                    cout << "adding value:"<<root->val<<endl;
                    root = root->left;
               }
               
               //pop the item from the stack
               root = mystack.top();
               mystack.pop();
              
               /******************************
                If the popped item has a right child and the right child 
                is at top of stack, then remove the right child from stack,
                push the root back and set root as root's right child.
                ********************************************/
               if(root->right && !mystack.empty() && root->right == mystack.top())
               {
                   mystack.pop();
                   mystack.push(root);
                   root = root->right;
               }
               else
               {
                    result.push_back(root->val);
                    root = NULL;
               }
        }
        
        return result;
    }
};


/**** another decent solution****/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> output;
        if(root == NULL)
            return output;

        stack<TreeNode*> stk;

        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *t = stk.top();
            stk.pop();
            output.push_back(t->val);
            if(t->left)
                stk.push(t->left);
            if(t->right)
                stk.push(t->right);
        }

        reverse(output.begin(), output.end());
        return output;
    }
};
