class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int j = 0, m = str2.length();
        for (int i = 0; i < str1.length() && j < m; ++i) {
            char c = str1.charAt(i);
            if (c == str2.charAt(j) || (c - 'a' + 1) % 26 + 'a' == str2.charAt(j)) {
                ++j;
            }
        }
        return j == m;
    }
}
