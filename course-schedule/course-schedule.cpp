class Solution {
public:
    bool isCyclic(int currCourse, vector <int> adj[], map<int,int> &mark, set<int> &prevCourses) {
        bool check = false;
        if (adj[currCourse].size() == 0) return false;
        mark[currCourse] = 1;
        prevCourses.insert(currCourse);
        
        for (int i = 0; i < adj[currCourse].size(); i++) 
            if (!mark[adj[currCourse][i]])
                check |= isCyclic(adj[currCourse][i], adj, mark, prevCourses);
            else if (prevCourses.count(adj[currCourse][i]) > 0) return true;
        prevCourses.erase(currCourse);
        return check;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];
        map <int, int> mark;
        set<int> temp;
        for (int i = 0; i < prerequisites.size(); i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for (int i = 0; i < numCourses; i++) {
            if (isCyclic(i, adj, mark, temp)) return false;
        }
        
        return true;
    }
};