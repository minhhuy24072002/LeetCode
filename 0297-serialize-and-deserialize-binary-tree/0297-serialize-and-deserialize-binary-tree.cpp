/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N";
        }
        string encode = to_string(root->val);
        encode += "," + serialize(root->left);
        encode += "," + serialize(root->right);
        return encode;
    }
    
    vector<string> splitStringBy(string s, char character) {
        string tempS = "";
        vector<string> result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != character) {
                tempS += s[i];
            } else {
                result.push_back(tempS);
                tempS = "";
            }
        }
        result.push_back(tempS);
        return result;
    }
    
    TreeNode* dfs(int &i, vector<string> &nodeVal) {
        if (i >= nodeVal.size() || nodeVal[i] == "N") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodeVal[i]));
        node->left = dfs(++i, nodeVal);
        node->right = dfs(++i, nodeVal);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodeVal = splitStringBy(data, ',');
        int i = 0;
        TreeNode* result = dfs(i, nodeVal);
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));