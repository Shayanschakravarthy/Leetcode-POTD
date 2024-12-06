class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    sort(banned.begin(), banned.end());  
    int ans = 0, sum = 0, bannedIndex = 0;

    for (int i = 1; i <= n; ++i) {
      while (bannedIndex < banned.size() && banned[bannedIndex] < i)
        ++bannedIndex;
      
      if (bannedIndex < banned.size() && banned[bannedIndex] == i)
        continue;

      if (sum + i > maxSum)
        break;

      sum += i;
      ++ans;
    }

    return ans;
  }
};
