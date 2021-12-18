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
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<TreeNode*, bool> mark;
        vector<vector<int>> res;
        vector<int> temp;
        bool check;
        
        while (!mark[root]) {
            queue <TreeNode*> nodeQueue;
            nodeQueue.push(root);
            TreeNode* currNode;
            
            while (nodeQueue.size()) {
                currNode = nodeQueue.front();
                nodeQueue.pop();
                check = true;
                
                if (currNode -> left != nullptr && !mark[currNode -> left]) {
                    nodeQueue.push(currNode -> left);
                    check = false;
                }
                
                if (currNode -> right != nullptr && !mark[currNode -> right]) {
                    nodeQueue.push(currNode -> right);
                    check = false;
                }
                
                if (check) {
                    temp.push_back(currNode -> val);
                    mark[currNode] = true;
                }
            }
            
            res.push_back(temp);
            while (temp.size()) temp.pop_back();
        }
        
        return res;
    }
};