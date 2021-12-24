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
    bool isEqual(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        
        if (root -> val == subRoot -> val)
            return isEqual(root -> left, subRoot -> left) & isEqual(root -> right, subRoot -> right);
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool check = false;
        if (root == nullptr || subRoot == nullptr) return false;
        if (root -> val == subRoot -> val)
            check = isEqual(root, subRoot);
        
        if (check)
            return check;
        
        return isSubtree(root -> left, subRoot) | isSubtree(root -> right, subRoot);
    }
};