class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adjacentWords;
        map<string, int> shortestPath;
        
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList[i].length(); j++) {
                string temp = wordList[i];
                temp[j] = '!';
                adjacentWords[temp].push_back(wordList[i]);
            }
        }
        
        for (int j = 0; j < beginWord.length(); j++) {
            string temp = beginWord;
            temp[j] = '!';
            adjacentWords[temp].push_back(beginWord);  
        }
        
        queue<string> wordQueue;
        shortestPath[beginWord] = 1;
        wordQueue.push(beginWord);
        
        while (wordQueue.size() > 0) {
            string currentWord = wordQueue.front();
            wordQueue.pop();
            
            for (int i = 0; i < currentWord.length(); i++) {
                string temp = currentWord;
                temp[i] = '!';
                for (int j = 0; j < adjacentWords[temp].size(); j++) {
                    if (adjacentWords[temp][j] != currentWord && shortestPath[adjacentWords[temp][j]] == 0) {
                        shortestPath[adjacentWords[temp][j]] = shortestPath[currentWord] + 1;
                        wordQueue.push(adjacentWords[temp][j]);
                        
                        if (adjacentWords[temp][j] == endWord) {
                            return shortestPath[adjacentWords[temp][j]];
                        }
                    }
                }
            }
        }
        return shortestPath[endWord];
    }
};