#include <string.h>

int takeCharacters(char* s, int k) {
    int cnt[3] = {0};
    int n = strlen(s);
    
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }

    if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;

    int maxWindow = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']--;

        while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            cnt[s[j] - 'a']++;
            j++;
        }

        maxWindow = (i - j + 1) > maxWindow ? (i - j + 1) : maxWindow;
    }

    return n - maxWindow;
}
