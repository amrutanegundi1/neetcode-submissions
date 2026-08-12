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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            return new TreeNode(val);
        }
        dfs(root, val);
        return root;
    }

    void dfs(TreeNode* root, int val)
    {

        if(val > root->val && root->right == nullptr)
        {
            root->right = new TreeNode(val);
            return;
        }

        if(val < root->val && root->left == nullptr)
        {
            root->left = new TreeNode(val);
            return;
        }
        if(val < root->val)
        {
            return dfs(root->left, val);
        }
        return dfs(root->right, val);
    }


};