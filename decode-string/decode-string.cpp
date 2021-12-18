class Solution {
public:
    string decodeString(string s) {
        int currNumber;
        stack <int> duplicateStack;
        stack <string> stringStack;
        string temp = "";
        
        stringStack.push("");
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                stringStack.top() += s[i];
            } else if (s[i] == '[') {
                duplicateStack.push(currNumber);
                stringStack.push("");
            } else if (s[i] == ']') {
                temp = stringStack.top();
                stringStack.pop();
                for (int j = 0; j < duplicateStack.top(); j++)
                    stringStack.top() += temp;
                duplicateStack.pop();    
            } else if (s[i] >= '0' && s[i] <= '9'){
                currNumber = s[i] - '0';
                while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    currNumber = currNumber * 10 + s[i] - '0';
                }
            }
        }
        
        return stringStack.top();
    }
};