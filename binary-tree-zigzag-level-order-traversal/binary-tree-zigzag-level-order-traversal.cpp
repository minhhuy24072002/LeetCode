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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        queue <TreeNode*> queueNode;
        map<TreeNode*, int> nodeLevel;
        
        if (root == nullptr) return res;
        
        temp.push_back(root -> val);
        res.push_back(temp);
        temp.pop_back();
        
        queueNode.push(root);
        nodeLevel[root] = 1;
        
        while (queueNode.size()) {
            TreeNode* currNode = queueNode.front();
            queueNode.pop();
            
            if (nodeLevel[currNode] > res.size()) {
                if (res.size() % 2 == 0) reverse(res[res.size() - 1].begin(), res[res.size() - 1].end());
                temp.push_back(currNode -> val);
                res.push_back(temp);
                temp.pop_back();
            } else if (res.size() > 1) res[nodeLevel[currNode] - 1].push_back(currNode -> val);
            
            if (currNode -> left) {
                queueNode.push(currNode -> left);
                nodeLevel[currNode -> left] = nodeLevel[currNode] + 1;
            }
            
            if (currNode -> right) {
                queueNode.push(currNode -> right);
                nodeLevel[currNode -> right] = nodeLevel[currNode] + 1;
            }
        }
        
        if (res.size() % 2 == 0) reverse(res[res.size() - 1].begin(), res[res.size() - 1].end());
        return res;
    }
};