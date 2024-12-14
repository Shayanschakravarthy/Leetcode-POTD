class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int start = 0;
        long long totalSubarrays = 0;
        deque<int> maxDeque, minDeque;

        for (int end = 0; end < nums.size(); ++end) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[end]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(end);
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[end]) {
                minDeque.pop_back();
            }
            minDeque.push_back(end);
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == start) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == start) {
                    minDeque.pop_front();
                }
                ++start;
            }
            totalSubarrays += (end - start + 1);
        }

        return totalSubarrays;
    }
};
