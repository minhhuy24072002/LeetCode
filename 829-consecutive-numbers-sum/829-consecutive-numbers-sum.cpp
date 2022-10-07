class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int sum = 1;
        int count = 1;
        int res = 0;
        while (sum <= n) {
            if ((n - sum) % count == 0) {
                res++;
            }
            count++;
            sum += count;
        }
        return res;
    }
};