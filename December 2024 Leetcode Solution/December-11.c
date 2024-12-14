int maximumBeauty(int* nums, int numsSize, int k) {
    int max_flower = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_flower) {
            max_flower = nums[i];
        }
    }

    int max_range = max_flower + k * 2 + 1;
    int* prefix_sum = (int*)calloc(max_range + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        prefix_sum[nums[i]]++;
        if (nums[i] + k * 2 + 1 <= max_range) {
            prefix_sum[nums[i] + k * 2 + 1]--;
        }
    }

    int max_beauty = 0, running_sum = 0;
    for (int i = 0; i <= max_range; i++) {
        running_sum += prefix_sum[i];
        if (running_sum > max_beauty) {
            max_beauty = running_sum;
        }
    }

    free(prefix_sum);
    return max_beauty;
}
