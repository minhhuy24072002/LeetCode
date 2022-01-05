class Solution {
public:
    int binarySearch(vector<int> res, int target) {
        int left = 0, right = res.size() - 1, mid, index;
        
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (target <= res[mid]) {
                index = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        
        return index;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> res;
        int index;
        
        res.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > res[res.size() - 1]) {
                res.push_back(nums[i]);
            } else {
                index = binarySearch(res, nums[i]);
                res[index] = nums[i];
            }
        }
        
        return res.size();
    }
};