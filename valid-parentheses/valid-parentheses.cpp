class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (brackets.size() == 0) return false;
                if (brackets.top() != '(') return false;
                brackets.pop();
            } else if (s[i] == ']') {
                if (brackets.size() == 0) return false;
                if (brackets.top() != '[') return false;
                brackets.pop();
            } else if (s[i] == '}') {
                if (brackets.size() == 0) return false;
                if (brackets.top() != '{') return false;
                brackets.pop();
            } else brackets.push(s[i]);
        }
        
        if (brackets.size() > 0) return false;
        
        return true;
    }
};