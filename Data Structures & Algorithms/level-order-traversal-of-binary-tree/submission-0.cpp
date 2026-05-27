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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root) {
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty()) {
                vector<TreeNode*> nodes;
                vector<int> level;
                for (int i = que.size() - 1; i >= 0; i--) {
                    level.push_back(que.front()->val);
                    nodes.push_back(que.front());
                    que.pop();
                }
                result.push_back(level);
                cout<<nodes.size()<<endl;
                for (int i = 0; i <= nodes.size() - 1; i++) {
                    if(nodes[i]->left)
                        que.push(nodes[i]->left);
                    if(nodes[i]->right)
                        que.push(nodes[i]->right);
                }
            }
        }
        return result;
    }
};
