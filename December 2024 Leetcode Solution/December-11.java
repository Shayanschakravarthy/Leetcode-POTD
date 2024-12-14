class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int max_flower = Arrays.stream(nums).max().getAsInt();
        int max_range = max_flower + k * 2 + 1;
        int[] prefix_sum = new int[max_range + 1];

        for (int flower : nums) {
            prefix_sum[flower]++;
            if (flower + k * 2 + 1 <= max_range) {
                prefix_sum[flower + k * 2 + 1]--;
            }
        }

        int max_beauty = 0, running_sum = 0;
        for (int value : prefix_sum) {
            running_sum += value;
            max_beauty = Math.max(max_beauty, running_sum);
        }

        return max_beauty;
    }
}
