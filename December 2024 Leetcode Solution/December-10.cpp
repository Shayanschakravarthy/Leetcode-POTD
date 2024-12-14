class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(), l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (isValid(s, n, mid)) l = mid;
            else r = mid - 1;
        }
        return l == 0 ? -1 : l;
    }

private:
    bool isValid(const string& s, int n, int x) {
        vector<int> freq(26, 0);
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            freq[s[i] - 'a'] += max(0, j - i - x + 1);
            if (freq[s[i] - 'a'] >= 3) return true;
            i = j;
        }
        return false;
    }
};
