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
    unordered_map<int, vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> curr;
        dfs(root, 0);
        int ind = 0;
        vector<vector<int>> result;
        while(res.find(ind) != res.end())
        {
            result.push_back(res[ind++]);
        }
        return result;
    }
    void dfs(TreeNode* root, int l)
    {
        if(root)
        {
            res[l].push_back(root->val);
            dfs(root->left, l+1);
            dfs(root->right, l+1);
        }
    }
};
