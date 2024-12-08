class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> maxValues(n);
        maxValues[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; --i) {
            maxValues[i] = max(maxValues[i + 1], events[i][2]);
        }

        vector<int> startTimes;
        for (const auto& event : events) {
            startTimes.push_back(event[0]);
        }

        int maxResult = 0;
        for (const auto& event : events) {
            int idx = upper_bound(startTimes.begin(), startTimes.end(), event[1]) - startTimes.begin();
            int value = event[2];
            if (idx < n) value += maxValues[idx];
            maxResult = max(maxResult, value);
        }

        return maxResult;
    }
};
