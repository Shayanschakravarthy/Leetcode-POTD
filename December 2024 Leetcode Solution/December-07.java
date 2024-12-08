class Solution {
    private boolean canDivide(int[] nums, int maxSize, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            operations += (num - 1) / maxSize;
            if (operations > maxOperations) return false;
        }
        return true;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1, right = Integer.MIN_VALUE;
        for (int num : nums) {
            right = Math.max(right, num);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
