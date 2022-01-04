class Solution {
public:
    string longestPalindrome(string s) {
        int start, end, resLength = 0, resStart, resEnd;
        string result = "";
        
        for (int i = 0; i < s.length(); i++){
    
            if (i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) {
                start = i - 1;
                end = i + 1;
                while (start > -1 && end < s.length() && s[start] == s[end]) {
                    start--;
                    end++;
                }
                
                if (end - start + 1 > resLength) {
                    resLength = end - start + 1;
                    resStart = start + 1;
                    resEnd = end - 1;
                }
            }
            
            if (i > 0 && s[i - 1] == s[i]) {
                start = i - 1;
                end = i;
                while (start > -1 && end < s.length() && s[start] == s[end]) {
                    start--;
                    end++;
                }
                
                if (end - start + 1 > resLength) {
                    resLength = end - start + 1;
                    resStart = start + 1;
                    resEnd = end - 1;
                }
            }
        }

        if (resLength > 1) {
            for (int i = resStart; i <= resEnd; i++) result += s[i];
        } else result += s[0];
        
        return result;
    }
};