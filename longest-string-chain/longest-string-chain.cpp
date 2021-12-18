class Solution {
public:
    bool check(string s1, string s2) {
        if (s1.length() - s2.length() != 1) return false;
        
        int i = 0, j = 0, count = 0;
        while (i < s1.length() && j < s2.length()){
            if (s1[i] != s2[j]) {
                count++;
            } else j++;
            
            i++;
            if (count > 1) return false;
        }
        
        return true;
    }
    int longestStrChain(vector<string>& words) {
        vector <pair<int,string>> wordsByLength;
        int res = 1;
        vector <int> dp(words.size());
        
        for (int i = 0; i < words.size(); i++) {
            wordsByLength.push_back(make_pair(words[i].length(),words[i]));
        }
        
        sort(wordsByLength.begin(), wordsByLength.end());

        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                //cout << i << ' ' << j << ' ' << check(wordsByLength[i].second,wordsByLength[j].second) << endl;
                if (check(wordsByLength[i].second,wordsByLength[j].second)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i] + 1);
        }
        
        return res;
    }
};