class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, start, end;
        
        for (int i = 0; i < s.length(); i++){
    
            if (i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) {
                start = i - 1;
                end = i + 1;
                while (start > -1 && end < s.length() && s[start] == s[end]) {
                    result++;
                    start--;
                    end++;
                }
            }
            
            if (i > 0 && s[i - 1] == s[i]) {
                start = i - 1;
                end = i;
                while (start > -1 && end < s.length() && s[start] == s[end]) {
                    result++;
                    start--;
                    end++;
                }
            }
            
            result++;
        }
        
        return result;
    }
};