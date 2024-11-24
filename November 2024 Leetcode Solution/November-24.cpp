class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        for (const auto& row : matrix) {
            for (int value : row) {
                int absValue = abs(value);
                totalSum += absValue;
                minAbsValue = min(minAbsValue, absValue);
                if (value < 0) negativeCount++;
            }
        }

        if (negativeCount % 2 != 0) {
            totalSum -= 2LL * minAbsValue;
        }

        return totalSum;
    }
};
