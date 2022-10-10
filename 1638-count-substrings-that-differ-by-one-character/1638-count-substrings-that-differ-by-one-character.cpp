class Solution {
public:
    int countSubstrings(string s, string t) {
        unordered_map<string, int> count;
        int res = 0;
        
        for (int i = 0; i < t.length(); i++) {
            string st = "";
            for (int j = i; j < t.length(); j++) {
                st += t[j];
                count[st]++;
                for (int index = 0; index < st.length(); index++) {
                    string temp = st;
                    temp[index] = '!';
                    count[temp]++;
                }
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            string st = "";
            for (int j = i; j < s.length(); j++) {
                st += s[j];
                for (int index = 0; index < st.length(); index++) {
                    string temp = st;
                    temp[index] = '!';
                    res += count[temp] - count[st];
                }
            }
        }
        return res;
    }
};