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
    void solution(TreeNode* root, int k, priority_queue<int> &nodeQueue) {
        if (root == nullptr) return;

        if (nodeQueue.size() < k || root -> val < nodeQueue.top())
        {
            if (nodeQueue.size() >= k && root -> val < nodeQueue.top())
                nodeQueue.pop();
            nodeQueue.push(root -> val);
            solution(root -> left, k, nodeQueue);
            solution(root -> right, k, nodeQueue);
        }  
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> nodeQueue;
        
        solution(root, k, nodeQueue);
        
        return nodeQueue.top();
    }
};