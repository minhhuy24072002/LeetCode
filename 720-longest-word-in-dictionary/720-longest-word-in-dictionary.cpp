class Solution {
public:
    unordered_map<string, bool> canBuilt;
    string longestWord(vector<string>& words) {
        int resLength = 0;
        string st, word, res = "";
        vector<pair<int, string>> wordWithLength;
        
        for (int i = 0; i < words.size(); i++) {
            word = words[i];
            wordWithLength.push_back({int(word.length()), word});
        }
        
        sort(wordWithLength.begin(), wordWithLength.end());
        canBuilt[""] = true;
        
        for (int i = 0; i < wordWithLength.size(); i++) {
            word = wordWithLength[i].second;
            //cout << word.length() << ' ' << word << endl;
            st = "";
            
            for (int i = 0; i < word.length() - 1; i++) st += word[i];
            
            if (canBuilt[st]) canBuilt[word] = true;
            cout << st << ' ' << word << ' ' << canBuilt[st] << ' ' << canBuilt[word] << endl;
            if (canBuilt[word]) {
                if (word.length() > resLength) {
                    resLength = word.length();
                    res = word;
                }
            }
        }
        
        return res;
    }
};