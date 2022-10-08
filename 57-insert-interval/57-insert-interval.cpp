class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.size() > 0) {
                if (intervals[i][0] <= newInterval[0]) {
                    if (intervals[i][1] >= newInterval[0]) {
                        intervals[i][1] = max(intervals[i][1], newInterval[1]);
                        newInterval.pop_back();
                        newInterval.pop_back();
                    }
                    res.push_back(intervals[i]);
                } else {
                    res.push_back(newInterval);
                    newInterval.pop_back();
                    newInterval.pop_back();
                    i--;
                }
            } else {
                if (res.back()[1] >= intervals[i][0]) {
                    res.back()[1] = max(intervals[i][1], res.back()[1]);
                } else {
                    res.push_back(intervals[i]);
                }
            }
        }
        if (newInterval.size() > 0) {
            res.push_back(newInterval);
        }
        return res;
    }
};