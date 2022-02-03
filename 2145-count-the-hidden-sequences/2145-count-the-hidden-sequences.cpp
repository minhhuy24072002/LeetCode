class Solution {
public:
    int check(int currVal, vector<int>& differences, int lower, int upper) {
        for (int i = 0; i < differences.size(); i++) {
            currVal += differences[i];
            if (currVal > upper) return 1;
            else if (currVal < lower) return 2;
        }
        
        return 0;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int resLeft = -INT_MAX, resRight = -INT_MAX, left = lower, right = upper, mid, checkVal;
        
        while (left <= right) {
            mid = (left + right) / 2;
            checkVal = check(mid, differences, lower, upper);
            if (checkVal == 0) {
                resLeft = mid;
                right = mid - 1;
            } else if (checkVal == 2) left = mid + 1;
            else right = mid - 1;
        }
        
        left = lower;
        right = upper;
        while (left <= right) {
            mid = (left + right) / 2;
            checkVal = check(mid, differences, lower, upper);
            if (checkVal == 0) {
                resRight = mid;
                left = mid + 1;
            } else if (checkVal == 2) left = mid + 1;
            else right = mid - 1;
        }
        
        if (resRight == -INT_MAX) return 0;
        return resRight - resLeft + 1;
    }
};