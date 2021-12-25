/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mark;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        if (mark[node]) return mark[node];
        
        Node* cloneNode = new Node(node -> val);
        mark[node] = cloneNode;
        
        for (int i = 0; i < (node -> neighbors).size(); i++) {
            (cloneNode -> neighbors).push_back(cloneGraph((node -> neighbors)[i]));
        }
    
        return cloneNode;
    }
};