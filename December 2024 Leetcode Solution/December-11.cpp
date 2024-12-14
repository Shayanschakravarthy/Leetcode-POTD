class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int max_flower = *max_element(nums.begin(), nums.end());
        int max_range = max_flower + k * 2 + 1;
        vector<int> prefix_sum(max_range + 1, 0);

        for (int flower : nums) {
            prefix_sum[flower]++;
            if (flower + k * 2 + 1 <= max_range) {
                prefix_sum[flower + k * 2 + 1]--;
            }
        }

        int max_beauty = 0, running_sum = 0;
        for (int value : prefix_sum) {
            running_sum += value;
            max_beauty = max(max_beauty, running_sum);
        }

        return max_beauty;
    }
};
