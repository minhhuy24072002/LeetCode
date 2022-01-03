class Solution {
public:
    bool check(int countS[], int countT[]) {
        for (int j = 0; j < 52; j++) {
            if (countS[j] < countT[j]) return false;
        }
        
        return true;
    }
    string minWindow(string s, string t) {
        int countT[52];
        int countS[52];
        
        for (int i = 0; i < 52; i++) {
            countT[i] = 0;
            countS[i] = 0;
        }
        
        for (int i = 0; i < t.length(); i++) 
            if (t[i] < 'a')
                countT[t[i] - 'A']++;
            else countT[t[i] - 'a' + 26]++;
        
        int start = 0, end = 0, resStart = -1, resEnd = -1, resLength = 1e5 + 1;
        string res = "";
         while (end < s.length()) {
            if (s[end] < 'a')
                countS[s[end] - 'A']++;
            else countS[s[end] - 'a' + 26]++;
        
            if (check(countS,countT)) {
                if (end - start + 1 < resLength) {
                    resLength = end - start + 1;
                    resStart = start;
                    resEnd = end;
                }
                
                while (start <= end) {
                    if (end - start + 1 < resLength) {
                        resLength = end - start + 1;
                        resStart = start;
                        resEnd = end;
                    }
                    if (s[start] < 'a')
                        countS[s[start] - 'A']--;
                    else countS[s[start] - 'a' + 26]--;
                    
                    if (s[start] < 'a')
                        if (countS[s[start] - 'A'] < countT[s[start] - 'A']) {
                            start++;
                            break;
                        }
                    
                    if (s[start] >= 'a')
                        if (countS[s[start] - 'a' + 26] < countT[s[start] - 'a' + 26]) {
                            start++;
                            break;
                        }
                    start++;
                }
            }
            end++;
        }

        if (resStart != -1)
            for (int i = resStart; i <= resEnd; i++) res += s[i];
        
        return res;
    }
};