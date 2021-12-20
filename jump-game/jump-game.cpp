class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthestIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cout << furthestIndex << endl;
            if (furthestIndex >= i)
                 furthestIndex = max(furthestIndex, i + nums[i]);
            else return false;
        }
        
        return true;
    }
};