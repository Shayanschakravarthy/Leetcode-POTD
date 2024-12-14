class Solution {
    public int maximumLength(String s) {
        int n = s.length(), l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (isValid(s, n, mid)) l = mid;
            else r = mid - 1;
        }
        return l == 0 ? -1 : l;
    }

    private boolean isValid(String s, int n, int x) {
        int[] freq = new int[26];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && s.charAt(j) == s.charAt(i)) j++;
            freq[s.charAt(i) - 'a'] += Math.max(0, j - i - x + 1);
            if (freq[s.charAt(i) - 'a'] >= 3) return true;
            i = j;
        }
        return false;
    }
}
