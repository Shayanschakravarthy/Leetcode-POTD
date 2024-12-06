class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> bannedSet = new HashSet<>();
        for (int b : banned) {
            if (b <= n)
                bannedSet.add(b);
        }

        int ans = 0, sum = 0;

        for (int i = 1; i <= n; i++) {
            if (bannedSet.contains(i))
                continue;

            if (sum + i > maxSum)
                break;

            sum += i;
            ans++;
        }

        return ans;
    }
}
