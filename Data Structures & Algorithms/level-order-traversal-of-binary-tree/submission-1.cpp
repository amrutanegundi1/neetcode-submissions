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
   vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        return result;
    }

    void dfs(TreeNode* root, int lvl)
    {
        if(!root)
            return;
        if(lvl == result.size())
        {
            result.push_back(vector<int>());
        }
        result[lvl].push_back(root->val);
        dfs(root->left, lvl+1);
        dfs(root->right, lvl+1);
    }
};
