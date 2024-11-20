class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        int[] cnt = new int[3];  

        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;

        int maxWindow = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            cnt[s.charAt(i) - 'a']--;  
            while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
                cnt[s.charAt(j) - 'a']++;  
                j++;  
            }

            maxWindow = Math.max(maxWindow, i - j + 1);
        }

        return n - maxWindow;  
    }
}
