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
    int dfs(TreeNode* root, int height) {
        if (root == nullptr) return height - 1;
        int res = height;
        if (root -> left)
            res = max(res, dfs(root -> left, height + 1));
        
        if (root -> right)
            res = max(res, dfs(root -> right, height + 1));
        
        return res;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};