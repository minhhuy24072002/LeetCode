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
    vector<vector<int>> res;
    
    void dfs(TreeNode* currNode, int currSum, vector<int> currPath, int targetSum) {
        currPath.push_back(currNode -> val);
        currSum += currNode -> val;
        
        if (currNode -> left == nullptr && currNode -> right == nullptr) {
            if (currSum == targetSum) res.push_back(currPath);
            return;
        }
        
        if (currNode -> left) dfs(currNode -> left, currSum, currPath, targetSum);
        if (currNode -> right) dfs(currNode -> right, currSum, currPath, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return res;
        vector<int> currPath;
        dfs(root, 0, currPath, targetSum);
        return res;
    }
};