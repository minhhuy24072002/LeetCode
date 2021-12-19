class Solution {
public:
    bool dfs(int currCourse, vector<int> adj[], map<int, int> &mark, set<int> &prevNodes, vector<int> &res) {
        bool check = false;
        mark[currCourse] = 1;
        if (adj[currCourse].size() == 0) {
            res.push_back(currCourse);
            return false;
        }
        prevNodes.insert(currCourse);
        
        for (int i = 0; i < adj[currCourse].size(); i++) {
            if (!mark[adj[currCourse][i]]) {
                check |= dfs(adj[currCourse][i], adj, mark, prevNodes, res);
            } else if (prevNodes.count(adj[currCourse][i]) > 0) {
                return true;
                prevNodes.erase(currCourse);
            }
        }
        
        res.push_back(currCourse);
        prevNodes.erase(currCourse);
        
        return check;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map <int, int> mark;
        set <int> prevNodes;
        vector <int> adj[numCourses];
        vector <int> res;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!mark[i]) {
                if (dfs(i, adj, mark, prevNodes, res)) {
                    res.clear();
                    return res;
                }
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};