int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    
    for (int i = 0; i < arrSize; ++i) {
        int target = 2 * arr[i];
        int left = (target >= 0 ? i + 1 : 0);
        int right = arrSize - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}
