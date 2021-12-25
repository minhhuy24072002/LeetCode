class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int parent[n], parent1, parent2, res = 0;
        
        for (int i = 0; i < n; i++) parent[i] = i;
        
        for (int i = 0; i < edges.size(); i++) {
            parent1 = edges[i][0];
            parent2 = edges[i][1];
            
            while (parent1 != parent[parent1]) parent1 = parent[parent1];
            while (parent2 != parent[parent2]) parent2 = parent[parent2];
            
            if (parent1 != parent2) parent[parent1] = parent2;
        }
        
        for (int i = 0; i < n; i++)
            if (parent[i] == i) res++;
        
        return res;
    }
};