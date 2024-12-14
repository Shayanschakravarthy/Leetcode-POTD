class Solution {
    public long continuousSubarrays(int[] nums) {
        int start = 0;
        long totalSubarrays = 0;
        Deque<Integer> maxDeque = new LinkedList<>();
        Deque<Integer> minDeque = new LinkedList<>();

        for (int end = 0; end < nums.length; end++) {
            while (!maxDeque.isEmpty() && nums[maxDeque.peekLast()] <= nums[end]) {
                maxDeque.pollLast();
            }
            maxDeque.offerLast(end);
            while (!minDeque.isEmpty() && nums[minDeque.peekLast()] >= nums[end]) {
                minDeque.pollLast();
            }
            minDeque.offerLast(end);
            while (nums[maxDeque.peekFirst()] - nums[minDeque.peekFirst()] > 2) {
                if (maxDeque.peekFirst() == start) {
                    maxDeque.pollFirst();
                }
                if (minDeque.peekFirst() == start) {
                    minDeque.pollFirst();
                }
                start++;
            }
            totalSubarrays += (end - start + 1);
        }

        return totalSubarrays;
    }
}
