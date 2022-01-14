class Solution {
private:
    int dfs(vector<vector<int>> &graph, vector<int>& informTime, int managerID) {
        int res = 0;
        
        for (int &eachEmployee : graph[managerID]) {
            res = max(res, dfs(graph, informTime, eachEmployee));
        }
        
        return res + informTime[managerID];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n); // {manager {employee}}
        
        if (n == 1) return 0;
        
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            graph[manager[i]].emplace_back(i);
        }
        
        return dfs(graph, informTime, headID);
    }
};