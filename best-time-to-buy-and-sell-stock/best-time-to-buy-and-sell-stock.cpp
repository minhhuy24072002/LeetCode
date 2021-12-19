class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = prices[prices.size() - 1], res = 0;
        
        for (int i = prices.size() - 2; i > -1; i--) {
            res = max(res, maxPrice - prices[i]);
            maxPrice = max(maxPrice,  prices[i]);
        }
        
        return res;
    }
};