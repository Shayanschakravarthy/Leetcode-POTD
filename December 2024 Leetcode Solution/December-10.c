int isValid(const char* s, int n, int x) {
    int freq[26] = {0};
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) j++;
        freq[s[i] - 'a'] += (j - i - x + 1) > 0 ? (j - i - x + 1) : 0;
        if (freq[s[i] - 'a'] >= 3) return 1;
        i = j;
    }
    return 0;
}

int maximumLength(char* s) {
    int n = strlen(s), l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (isValid(s, n, mid)) l = mid;
        else r = mid - 1;
    }
    return l == 0 ? -1 : l;
}
