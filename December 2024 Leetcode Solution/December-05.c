
bool canChange(char* start, char* target) {
    int n = strlen(start);
    int i = 0, j = 0;

    for (int k = 0; k < n; k++) {
        if (start[k] != '_') {
            while (j < n && target[j] == '_') j++;

            if (j == n || start[k] != target[j]) return false;

            if ((start[k] == 'L' && k < j) || (start[k] == 'R' && k > j)) return false;

            j++;
        }
    }

    while (j < n) {
        if (target[j] != '_') return false;
        j++;
    }

    return true;
}
