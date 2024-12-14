class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;

        for (int i = 0; i < n; i++) {
            indexedNums.emplace_back(nums[i], i);
        }
        
        sort(indexedNums.begin(), indexedNums.end());
        vector<bool> vis(n, false);
        long long ans = 0;

        for (auto& [val, idx] : indexedNums) {
            if (!vis[idx]) {
                ans += val;
                vis[idx] = true;
                if (idx > 0) vis[idx - 1] = true;
                if (idx < n - 1) vis[idx + 1] = true;
            }
        }

        return ans;
    }
};
