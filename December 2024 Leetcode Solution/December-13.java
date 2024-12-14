class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        long ans = 0;
        boolean[] visited = new boolean[n];
        List<int[]> indexedNums = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            indexedNums.add(new int[]{nums[i], i});
        }

        indexedNums.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

        for (int[] pair : indexedNums) {
            int value = pair[0], idx = pair[1];
            if (!visited[idx]) {
                ans += value;
                visited[idx] = true;
                if (idx > 0) visited[idx - 1] = true;
                if (idx < n - 1) visited[idx + 1] = true;
            }
        }

        return ans;
    }
}
