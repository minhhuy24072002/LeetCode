class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> res, prefixProduct(nums.size()), suffixProduct(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            prefixProduct[i] = product;
        }

        product = 1;
        for (int i = nums.size() - 1; i > -1; i--) {
            product *= nums[i];
            suffixProduct[i] = product;
        }
        
        for (int i = 0; i < nums.size(); i++) 
            if (i - 1 < 0) res.push_back(suffixProduct[i + 1]);
        else if (i + 1 >= nums.size()) res.push_back(prefixProduct[i - 1]);
        else res.push_back(suffixProduct[i + 1] * prefixProduct[i - 1]);
        
        return res;
    }
};