char* addSpaces(char* s, int* spaces, int spacesSize) {
    int n = strlen(s);
    char* result = (char*)malloc((n + spacesSize + 1) * sizeof(char));
    int resultIndex = 0, spaceIndex = 0;

    for (int i = 0; i < n; i++) {
        if (spaceIndex < spacesSize && i == spaces[spaceIndex]) {
            result[resultIndex++] = ' ';
            spaceIndex++;
        }
        result[resultIndex++] = s[i];
    }
    result[resultIndex] = '\0'; 
    return result;
}

2)
char* addSpaces(char* s, int* spaces, int spacesSize) {
    int n = strlen(s);
    int m = spacesSize;
    char* result = (char*)malloc(n + m + 1);  // +1 for null terminator
    
    int i = 0, j = 0, resultIndex = 0;
    while (i < n) {
        if (j < m && i == spaces[j]) {
            result[resultIndex++] = ' ';
            j++;
        }
        result[resultIndex++] = s[i++];
    }

    result[resultIndex] = '\0';  // Null-terminate the string
    return result;
}
