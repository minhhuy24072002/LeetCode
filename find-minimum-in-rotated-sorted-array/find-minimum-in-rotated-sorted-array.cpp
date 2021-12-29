class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid, rotateTimes = 0;
        
        if (nums.size() == 2) return min(nums[0], nums[1]);
        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] >= nums[0]) {
                rotateTimes = mid + 1;
                left = mid + 1;
            } else right = mid - 1;
        }

        return nums[rotateTimes % nums.size()];
    }
};