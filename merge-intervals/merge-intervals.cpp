class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) end = max(end, intervals[i][1]);
            else {
                temp.push_back(start);
                temp.push_back(end);
                
                res.push_back(temp);
                
                temp.pop_back();
                temp.pop_back();
                
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        temp.push_back(start);
        temp.push_back(end);
                
        res.push_back(temp);
                
        start = intervals[intervals.size() - 1][0];
        end = intervals[intervals.size() - 1][1];
        
        return res;
    }
};