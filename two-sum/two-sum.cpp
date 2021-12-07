class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> cnt;
        vector <int> res;
        for (int i = 0; i < nums.size(); i++){
            if (cnt[target - nums[i]] != 0)
            {
                res.push_back(i);
                res.push_back(cnt[target - nums[i]] - 1);
                return res;
            }
            cnt[nums[i]] = i + 1;
        }
        
        return res;
    }
};