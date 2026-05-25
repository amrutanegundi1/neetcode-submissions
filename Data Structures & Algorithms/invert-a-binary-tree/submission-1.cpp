/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // if(root == nullptr)
        //     return root;
        // else
        // {
        //     TreeNode *temp = root->right;
        //     root->right = root->left;
        //     root->left = temp;
        //     invertTree(root->right);
        //     invertTree(root->left);
        // }
        // return root;
        if(root == nullptr)
            return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *curr = que.front();
            que.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if(curr->left)
                que.push(curr->left);
            if(curr->right)
                que.push(curr->right);

        }
        return root;
    }
};
