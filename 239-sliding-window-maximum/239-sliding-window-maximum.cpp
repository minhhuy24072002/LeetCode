class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> window;
        vector<int> res;
        
        for (int i = 0; i < k; i++) {
            window.push({nums[i], i});
        }
        res.push_back(window.top().first);
        int l = 1, r = l + k - 1;
        while (r < nums.size()) {
            while (window.size() > 0 && window.top().second < l) {
                window.pop();
            }
            window.push({nums[r], r});
            l++;
            r++;
            res.push_back(window.top().first);
        }
        return res;
    }
};