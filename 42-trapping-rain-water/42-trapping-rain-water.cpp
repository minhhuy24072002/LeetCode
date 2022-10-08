class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0, leftMax = height[0], rightMax = height[height.size() - 1];
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    res += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    res += rightMax - height[right];
                }
                right--;
            }
        }
        return res;
    }
};