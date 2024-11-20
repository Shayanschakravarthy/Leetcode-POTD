class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3] = {}; 
        int n = s.size();

        for (char c : s) ++cnt[c - 'a'];
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;

        cnt[0] -= k; cnt[1] -= k; cnt[2] -= k;
        int maxWindow = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            --cnt[s[i] - 'a']; 
            while (cnt[s[i] - 'a'] < 0) {
                ++cnt[s[j++] - 'a'];
            }
            maxWindow = max(maxWindow, i - j + 1);
        }

        return n - maxWindow;
    }
};
