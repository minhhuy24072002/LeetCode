class Solution {
public:
    bool check(int left, int right, int mid, vector<int> nums) {
        if (nums[mid] < nums[0]) return true;
        return false;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0, res = -1;
        
        if (nums[0] > nums[nums.size() - 1])
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) break;
            if (check(left, right, mid, nums)) {
                right = mid - 1;
            } else left = mid + 1;
        }
        
        left = mid; 
        right = left + nums.size() - 1;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid % nums.size()] == target) {
                res = mid % nums.size();
                break;
            } else if (nums[mid % nums.size()] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return res;
    }
};