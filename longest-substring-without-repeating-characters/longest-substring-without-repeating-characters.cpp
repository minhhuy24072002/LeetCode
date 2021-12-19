class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, res = 0;
        map <char, int> count;
        
        while (end < s.length()) {
            count[s[end]]++;
            while (count[s[end]] > 1) {
                count[s[start]]--;
                start++;
            }
            
            res = max(res, end - start + 1);
            end++;
        }
        
        return res;
    }
};