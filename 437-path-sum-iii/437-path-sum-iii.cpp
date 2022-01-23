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
    int res;
    unordered_map<int, int> countSum;
    
    void dfs(TreeNode* currNode, int currSum, int targetSum) {
        countSum[currSum]++;
        res += countSum[currSum + currNode -> val - targetSum];
        
        if (currNode -> left) dfs(currNode -> left, currSum + currNode -> val, targetSum);
        if (currNode -> right) dfs(currNode -> right, currSum + currNode -> val, targetSum);
        countSum[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return res;
        vector<int> currPath;
        dfs(root, 0, targetSum);
        return res;
    }
};