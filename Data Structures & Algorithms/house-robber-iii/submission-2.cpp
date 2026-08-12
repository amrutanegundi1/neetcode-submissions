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
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        if(mp.find(root) != mp.end())
        {
            return mp[root];
        }
        //skip the node
        int res1 = dfs(root->left);
        int res2 = dfs(root->right);

        //include the node
        int res3 = root->val, res4 = 0, res5 = 0, res6 = 0, res7 = 0;
        if(root->left)
        {
            res4 = dfs(root->left->left);
            res5 = dfs(root->left->right);

        }
        if(root->right)
        {
            res6 = dfs(root->right->left);
            res7 = dfs(root->right->right);
        }
        mp[root] = max(res1+res2, res3+res4+res5+res6+res7); 
        return mp[root];

    }
};