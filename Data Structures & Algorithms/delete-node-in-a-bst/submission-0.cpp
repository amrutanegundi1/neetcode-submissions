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
    TreeNode* deleteNode(TreeNode* root, int key) { return dfs(root, key); }

    TreeNode* dfs(TreeNode* root, int key) {
        if (!root) {
            return root;
        }

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }
            curr->left = root->left;
            return root->right;
        } else if (root->val > key) {
            root->left = dfs(root->left, key);
        } else {
            root->right = dfs(root->right, key);
        }
        return root;
    }
};