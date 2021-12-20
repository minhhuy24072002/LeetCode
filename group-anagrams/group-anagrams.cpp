class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groupAnagrams;
        vector<int> count(26);
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < 26; j++) count[j] = 0;
            
            for (int j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a']++;
            }
            
            groupAnagrams[count].push_back(strs[i]);
        }
        
        for (auto group: groupAnagrams) {
            res.push_back(group.second);
        }
        
        return res;
    }
};