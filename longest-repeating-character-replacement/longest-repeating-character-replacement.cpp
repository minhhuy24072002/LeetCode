class Solution {
public:
    bool check(int resLength, string s, int count[][26], int k) {
        int maxOccur = 0;
        for (int i = 0; i <= s.length() - resLength; i++) {
            maxOccur = 0;
            if (i > 0)
                for (int letter = 0; letter < 26; letter++) maxOccur = max(maxOccur, count[i + resLength - 1][letter] - count[i - 1][letter]);
            else for (int letter = 0; letter < 26; letter++) maxOccur = max(maxOccur, count[i + resLength - 1][letter]);

            if (resLength - maxOccur <= k) return true; 
        }
        
        return false;
    }
    int binarySearch(string s, int count[][26], int k) {
        int left = 1, right = s.length(), mid, res = 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (check(mid, s, count, k)) {
                res = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        
        return res;
    }
    int characterReplacement(string s, int k) {
        int count[s.length()][26];
        
        for (int i = 0; i < s.length(); i++)
            for (int letter = 0; letter < 26; letter++) count[i][letter] = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i > 0)
                for (int letter = 0; letter < 26; letter++) count[i][letter] = count[i - 1][letter];
            
            count[i][s[i] - 'A']++;
        }
        
        return binarySearch(s, count, k);
    }
};