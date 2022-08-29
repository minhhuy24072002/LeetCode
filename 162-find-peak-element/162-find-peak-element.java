public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1, result = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums.length - 1 == mid || nums[mid] > nums[mid + 1]) {
                result = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return result;
    }
}