class Solution {
public:
    bool isCyclic(int x, int prevNode, vector<int> adj[], set<int> &prevNodes, map<int, int> &mark){
        bool check = false;
        mark[x] = 1;
        prevNodes.insert(x);
        
        for (auto adjNode : adj[x]) 
        if (adjNode != prevNode) {
            if (!(mark[adjNode])) {
                check |= isCyclic(adjNode, x, adj, prevNodes, mark);
            } else if (prevNodes.count(adjNode) > 0) {
                prevNodes.erase(x);
                return true;
            }
        }
            
        
        prevNodes.erase(x);
        return check;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        set<int> prevNodes;
        map<int, int> mark;
        //cout << 'x ' << edges[0][0] << endl;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        if (isCyclic(0, -1, adj, prevNodes, mark)) return false;
        
        for (int i = 0; i < n; i++)
            if (!mark[i]) return false;
        
        return true;
    }
};