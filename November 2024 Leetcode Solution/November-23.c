char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes) {
    int rows = boxSize;
    int cols = *boxColSize;

    char** result = (char**)malloc(cols * sizeof(char*));
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++) {
        result[i] = (char*)malloc(rows * sizeof(char));
        (*returnColumnSizes)[i] = rows;
    }

    for (int i = 0; i < rows; i++) {
        int empty_spot = cols - 1;
        for (int j = cols - 1; j >= 0; j--) {
            if (box[i][j] == '#') {
                box[i][j] = '.';
                box[i][empty_spot--] = '#';
            } else if (box[i][j] == '*') {
                empty_spot = j - 1;
            }
        }
        for (int j = 0; j < cols; j++) {
            result[j][rows - 1 - i] = box[i][j];
        }
    }

    *returnSize = cols;
    return result;
}
