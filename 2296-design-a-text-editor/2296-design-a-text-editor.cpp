class TextEditor {
public:
    list<char> st;
    list<char>::iterator cursor;
    
    TextEditor() {
        st.push_back('\0');
        cursor = st.begin();
    }
    
    void addText(string text) {
        for (int i = 0; i < text.length(); i++) {
            cursor++;
            st.insert(cursor, text[i]);
            cursor--;
        }
    }
    
    int deleteText(int k) {
        int counter = 0;
        if (st.empty()) {
            return counter;
        }
        while (k--) {
            if (cursor == st.begin()) {
                break;
            }
            
            st.erase(cursor--);
            counter++;
        }
        return counter;
    }
    
    string cursorLeft(int k) {
        int counter = k;
        while (counter-- && cursor != st.begin()) {
            cursor--;
        }
        
        counter = 10;
        while (counter) {
            counter--;
            if (cursor == st.begin()) {
                break;
            }
            if (counter > 0) cursor--;
        }
        string result = "";
        counter = 10 - counter;
        while (counter--) {
            if (*cursor != '\0') result.push_back(*cursor);
            if (counter > 0) cursor++;
        }
        return result;
    }
    
    string cursorRight(int k) {
        int counter = k;
        while (counter-- && cursor != st.end()) {
            cursor++;
        }
        if (cursor == st.end()) {
            cursor--;
        }

        counter = 10;
        while (counter) {
            counter--;
            if (cursor == st.begin()) {
                break;
            }
            if (counter > 0) cursor--;
        }
        
        string result = "";
        counter = 10 - counter;
        while (counter--) {
            if (*cursor != '\0') result.push_back(*cursor);
            if (counter > 0) cursor++;
        }
        return result;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */