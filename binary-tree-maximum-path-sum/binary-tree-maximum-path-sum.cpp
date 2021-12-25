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
    int maxGain(TreeNode* node, int &maxSum) {
        if (node == nullptr) return 0;
        
        int left_gain = max(maxGain(node -> left, maxSum), 0);
        int right_gain = max(maxGain(node -> right, maxSum), 0);
        
        int newSum = node -> val + left_gain + right_gain;
        
        maxSum = max(maxSum, newSum);
        
        return node -> val + max(right_gain, left_gain);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = -1001;
        
        maxGain(root, maxSum);
        return maxSum;
    }
};