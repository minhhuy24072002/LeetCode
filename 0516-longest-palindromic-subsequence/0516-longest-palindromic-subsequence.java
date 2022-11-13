class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] MaxPalSub = new int[s.length()][s.length()];
        int result = 0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = j; i > -1; i--) {
                if (i == j) {
                    MaxPalSub[i][j] = 1;
                } else if (Character.compare(s.charAt(i), s.charAt(j)) == 0) {
                    MaxPalSub[i][j] = MaxPalSub[i + 1][j - 1] + 2;
                } else {
                    MaxPalSub[i][j] = Math.max(MaxPalSub[i + 1][j], MaxPalSub[i][j - 1]);
                }
            result = Math.max(result, MaxPalSub[i][j]);
            }
        }
        return result;
    }
}