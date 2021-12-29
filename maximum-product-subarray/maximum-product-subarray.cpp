class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstNegativeProduct = 1, res = -INT_MAX, product = 1;
        bool hasNegative = false;
        
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            
            if (product < 0) {
                if (!hasNegative) {
                    firstNegativeProduct = product;
                    hasNegative = true;
                } else res = max(res, product / firstNegativeProduct);
            }
            res = max(res, product);
            
            if (product == 0) {
                product = 1;
                hasNegative = false;
            }
        }
        
        return res;
    }
};