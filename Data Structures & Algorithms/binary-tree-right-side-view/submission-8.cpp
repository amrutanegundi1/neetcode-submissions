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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            cout<<que.size()<<endl;
            bool added = false;
            for (int i = que.size() - 1; i >= 0; i--) {
                TreeNode* tp = que.front();
                if (tp) {
                    if (!added) {
                        res.push_back(tp->val);
                        added = true;
                    }
                    que.push(tp->right);
                    que.push(tp->left);
                }
                que.pop();
            }
        }
        return res;
    }
};
