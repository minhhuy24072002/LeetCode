class Solution {
    public String minRemoveToMakeValid(String input) {
        int count = 0;
        String temp = new String();
    
        for (int i = 0; i < input.length(); i++) {
            char letter = input.charAt(i);
            if (letter == '(') {
                count++;
                temp = temp + letter;
            } 
            else if (letter == ')' ) {
                if (!(count == 0)) {
                    count--;
                    temp = temp + letter;
                }
            } 
            else {
              temp = temp + letter;
            }
        }
        System.out.print(temp);
        String res = new String();
        if (!(count == 0)) {
            for (int i = temp.length() - 1; i >= 0; i--) {
                if (temp.charAt(i) == '(') {
                      if (!(count == 0))
                        count--;
                      else res = temp.charAt(i) + res;
                } else {
                    res = temp.charAt(i) + res;
                }
            }
        } else res = temp;
        
        return res;
    }
}