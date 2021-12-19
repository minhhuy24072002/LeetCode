/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> res;
        vector<Node*> temp;
        queue <Node*> queueNode;
        map<Node*, int> nodeLevel;
        
        if (root == nullptr) return root;
        
        temp.push_back(root);
        res.push_back(temp);
        temp.pop_back();
        
        queueNode.push(root);
        nodeLevel[root] = 1;
        
        while (queueNode.size()) {
            Node* currNode = queueNode.front();
            queueNode.pop();
            
            if (nodeLevel[currNode] > res.size()) {
                temp.push_back(currNode);
                res.push_back(temp);
                temp.pop_back();
            } else if (res.size() > 1) res[nodeLevel[currNode] - 1].push_back(currNode);
            
            if (currNode -> left) {
                queueNode.push(currNode -> left);
                nodeLevel[currNode -> left] = nodeLevel[currNode] + 1;
            }
            
            if (currNode -> right) {
                queueNode.push(currNode -> right);
                nodeLevel[currNode -> right] = nodeLevel[currNode] + 1;
            }
        }
        
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size() - 1; j++) {
                res[i][j] -> next = res[i][j + 1];
            }
            
            res[i][res[i].size() - 1] -> next = nullptr;
        }
        
        return root;
    }
};