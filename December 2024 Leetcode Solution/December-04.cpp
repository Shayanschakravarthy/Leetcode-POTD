class Solution {
public:
    bool canMakeSubsequence(string& str1, string& str2) {
        int j = 0, m = str2.size();
        for (char c : str1) {
            if (j < m && (c == str2[j] || (c + 1 - 'a') % 26 + 'a' == str2[j])) {
                if (++j == m) return true;
            }
        }
        return j == m;
    }
};
