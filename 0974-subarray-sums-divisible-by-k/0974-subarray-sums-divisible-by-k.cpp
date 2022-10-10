class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        int sum = 0, res = 0;
        remainderCount[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > 0) {
                sum %= k;
            } else {
                sum = (k - (-sum % k)) % k;
            }
            
            res += remainderCount[sum];
            remainderCount[sum]++;
        }
        
        return res;
    }
};