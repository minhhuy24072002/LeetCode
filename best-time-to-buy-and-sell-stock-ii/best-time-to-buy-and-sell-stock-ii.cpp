class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_with_stock=-1e9,best_without_stock=0;
        for (int a:prices)
        {
            best_with_stock=max(best_with_stock,best_without_stock-a);
            best_without_stock=max(best_without_stock,best_with_stock+a);
        }
        return best_without_stock;
    }
};