bool canDivide(int* nums, int numsSize, int maxSize, int maxOperations) {
    int operations = 0;
    for (int i = 0; i < numsSize; i++) {
        operations += (nums[i] - 1) / maxSize;
        if (operations > maxOperations) return false;
    }
    return true;
}

int minimumSize(int* nums, int numsSize, int maxOperations) {
    int left = 1, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) right = nums[i];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canDivide(nums, numsSize, mid, maxOperations)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
