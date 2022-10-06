class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> remainder;
        remainder[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = k - ((-sum) % k);
            }
            sum %= k;
            //cout << sum << endl;
            res += remainder[sum];
            remainder[sum]++;
        }
        return res;
    }
};