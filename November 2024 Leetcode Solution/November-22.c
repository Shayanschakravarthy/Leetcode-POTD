int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    char **keyArray = (char **)malloc(matrixSize * sizeof(char *));
    int *count = (int *)calloc(matrixSize, sizeof(int));
    int maxCount = 0;

    for (int i = 0; i < matrixSize; i++) {
        int flip = matrix[i][0] == 1;
        keyArray[i] = (char *)malloc(matrixColSize[i] + 1);  

        for (int j = 0; j < matrixColSize[i]; j++) {
            if (flip) {
                keyArray[i][j] = '0' + (1 - matrix[i][j]);  
            } else {
                keyArray[i][j] = '0' + matrix[i][j];  
            }
        }
        keyArray[i][matrixColSize[i]] = '\0'; 

        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(keyArray[i], keyArray[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            count[i] = 1;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        free(keyArray[i]);
    }
    free(keyArray);
    free(count);

    return maxCount;
}
