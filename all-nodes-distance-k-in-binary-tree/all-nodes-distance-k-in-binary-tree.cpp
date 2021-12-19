/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, int> distanceFromTarget;
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, int> mark;
        vector<int> res;
        queue<TreeNode*> nodeQueue;
        
        if (k == 0) {
            res.push_back(target -> val);
            return res;
        }
        
        nodeQueue.push(root);
        while (nodeQueue.size()) {
            TreeNode* currNode = nodeQueue.front();
            nodeQueue.pop();
            
            if (currNode == target) continue;
            
            if (currNode -> left) {
                parent[currNode -> left] = currNode;
                nodeQueue.push(currNode -> left);
            }
            
            if (currNode -> right) {
                parent[currNode -> right] = currNode;
                nodeQueue.push(currNode -> right);
            }
        }
        
        nodeQueue.push(target);
        while (nodeQueue.size()) {
            TreeNode* currNode = nodeQueue.front();
            mark[currNode] = 1;
            nodeQueue.pop();
            
            if (currNode -> left && !mark[currNode -> left]) {
                distanceFromTarget[currNode -> left] = distanceFromTarget[currNode] + 1;
                if (distanceFromTarget[currNode -> left] == k) res.push_back((currNode -> left) -> val);
                else  nodeQueue.push(currNode -> left);
            }
            
            if (currNode -> right && !mark[currNode -> right]) {
                distanceFromTarget[currNode -> right] = distanceFromTarget[currNode] + 1;
                if (distanceFromTarget[currNode -> right] == k) res.push_back((currNode -> right) -> val);
                else  nodeQueue.push(currNode -> right);
            }
            
            if (parent[currNode] && !mark[parent[currNode]]) {
                distanceFromTarget[parent[currNode]] = distanceFromTarget[currNode] + 1;
                if (distanceFromTarget[parent[currNode]] == k) res.push_back((parent[currNode]) -> val);
                else  nodeQueue.push(parent[currNode]);
            }
        }
        
        return res;
    }
};