class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> patternCount = new HashMap<>();
        int maxCount = 0;

        for (int[] row : matrix) {
            StringBuilder pattern = new StringBuilder();
            int firstElement = row[0];

            for (int val : row) {
                pattern.append((val ^ firstElement) == 0 ? '0' : '1');
            }

            patternCount.put(pattern.toString(), patternCount.getOrDefault(pattern.toString(), 0) + 1);
            maxCount = Math.max(maxCount, patternCount.get(pattern.toString()));
        }

        return maxCount;
    }
}
