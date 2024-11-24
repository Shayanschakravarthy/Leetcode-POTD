long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long totalSum = 0;
    int minAbsValue = INT_MAX;
    int negativeCount = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int value = matrix[i][j];

            if (value < 0) {
                negativeCount++;
                value = -value;
            }

            totalSum += value;

            if (value < minAbsValue) {
                minAbsValue = value;
            }
        }
    }

    if (negativeCount & 1) { 
        totalSum -= 2LL * minAbsValue;
    }

    return totalSum;
}
