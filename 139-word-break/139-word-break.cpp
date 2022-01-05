class Solution {
public:
    bool isEqual(string s, int index, string word) {
        for (int i = index, j = 0; i < s.length() && j < word.length(); i++, j++) {
            if (s[i] != word[j]) return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false);
        string word;
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                word = wordDict[j];
                
                if (i + word.length() - 1 < s.length())
                    if (isEqual(s, i, word)) {
                        if (i > 0) dp[i + word.length() - 1] = dp[i + word.length() - 1] | dp[i - 1];
                        else dp[i + word.length() - 1] = true;
                        //cout << i << ' ' << i + word.length() - 1
                    }
            }
        }
        return dp[s.length() - 1];
    }
};