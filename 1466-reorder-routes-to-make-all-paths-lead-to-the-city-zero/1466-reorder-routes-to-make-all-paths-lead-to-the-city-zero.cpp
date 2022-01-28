class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, bool> visited;
        vector<int> adjR[n + 1];
        vector<int> adj[n + 1];
        int res = 0, currCity;
        
        for (int i = 0; i < connections.size(); i++) {
            int a, b;
            a = connections[i][0];
            b = connections[i][1];
            
            adj[a].push_back(b);
            adjR[b].push_back(a);
        }
        
        queue<int> city;
        city.push(0);
        
        while (city.size()) {
            currCity = city.front();
            visited[currCity] = true;
            city.pop();
            
            for (int i = 0; i < adj[currCity].size(); i++)
                if (!visited[adj[currCity][i]]) {
                    city.push(adj[currCity][i]);
                    visited[adj[currCity][i]] = true;
                    res++;
                    //cout << 'x' << ' ' << currCity << ' ' << adj[currCity][i] << endl;
                }
            
            for (int i = 0; i < adjR[currCity].size(); i++)
                if (!visited[adjR[currCity][i]]) {
                    city.push(adjR[currCity][i]);
                    visited[adjR[currCity][i]] = true;
                    //cout << currCity << ' ' << adjR[currCity][i] << endl;       
                }
        }
        
        return res;
    }
};