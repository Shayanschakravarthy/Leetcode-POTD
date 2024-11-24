class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long totalSum = 0;
        int minAbsValue = Integer.MAX_VALUE;
        int negativeCount = 0;

        for (int[] row : matrix) {
            for (int value : row) {
                int absValue = Math.abs(value);
                totalSum += absValue;
                minAbsValue = Math.min(minAbsValue, absValue);
                if (value < 0) negativeCount++;
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2L * minAbsValue;
        }

        return totalSum;
    }
}
