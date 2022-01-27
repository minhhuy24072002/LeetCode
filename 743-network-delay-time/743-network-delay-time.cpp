class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        int timeTaken[n + 1];
        int res = 0, reachedNode = 0;
        
        for (int i = 0; i <= n; i++) timeTaken[i] = 600001;
        int u, v, w;
        for (int i = 0; i < times.size(); i++) {
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> edgeQueue;
        
        timeTaken[k] = 0;
        edgeQueue.push({0, {k, k}});
        
        int currNode, neighbor, time;
        while (edgeQueue.size()) {
            w = edgeQueue.top().first;
            u = edgeQueue.top().second.first;
            v = edgeQueue.top().second.second;
            edgeQueue.pop();
            
            timeTaken[v] = min(timeTaken[v], timeTaken[u] + w);
            currNode = v;
            
            for (int i = 0; i < adj[currNode].size(); i++) {
                neighbor = adj[currNode][i].first;
                time = adj[currNode][i].second;
                if (timeTaken[neighbor] > timeTaken[currNode] + time) 
                    edgeQueue.push({time, {currNode, neighbor}});
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (timeTaken[i] != 600001) reachedNode++;
            res = max(res, timeTaken[i]);
        }
        if (reachedNode != n) return -1;
        return res;
    }
};