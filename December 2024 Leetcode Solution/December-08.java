class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));

        int n = events.length;
        int[] maxValues = new int[n];
        maxValues[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            maxValues[i] = Math.max(maxValues[i + 1], events[i][2]);
        }

        int maxResult = 0;
        for (int i = 0; i < n; ++i) {
            int nextIndex = binarySearch(events, events[i][1]);
            int currentValue = events[i][2];
            if (nextIndex < n) {
                currentValue += maxValues[nextIndex];
            }
            maxResult = Math.max(maxResult, currentValue);
        }

        return maxResult;
    }

    private int binarySearch(int[][] events, int target) {
        int low = 0, high = events.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
