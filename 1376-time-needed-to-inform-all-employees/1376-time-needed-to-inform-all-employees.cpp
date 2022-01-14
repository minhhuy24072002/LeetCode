class Solution {
public:
    int dfs(int currEmployee, vector<int> &informTime,  vector<vector<int>> &adj) {
        
        int maxTime = 0;
        
        for (int i : adj[currEmployee]) {
            maxTime = max(maxTime, dfs(i, informTime, adj));
        }
        
        return maxTime + informTime[currEmployee];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        if (n == 1) return 0;
        
        for (int i = 0; i < manager.size(); i++)
            if (manager[i] > -1)
                adj[manager[i]].push_back(i);
        
        return dfs(headID, informTime, adj);
    }
};