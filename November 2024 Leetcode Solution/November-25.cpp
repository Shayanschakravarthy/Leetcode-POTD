class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    constexpr int m = 2;
    constexpr int n = 3;
    const char* goal = "123450"; 
    string start;

    for (const auto& row : board)
      for (int num : row)
        start += '0' + num;

    if (start == goal)
      return 0;

    queue<pair<string, int>> q; 
    unordered_set<string> seen{start}; 
    q.emplace(start, 0);

    while (!q.empty()) {
      auto [state, steps] = q.front();
      q.pop();

      const int zeroIndex = state.find('0');
      const int i = zeroIndex / n;
      const int j = zeroIndex % n;

      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;

        if (x < 0 || x >= m || y < 0 || y >= n)
          continue;

        const int swappedIndex = x * n + y;
        string nextState = state;
        swap(nextState[zeroIndex], nextState[swappedIndex]);

        if (nextState == goal)
          return steps + 1;

        if (seen.insert(nextState).second)
          q.emplace(nextState, steps + 1);
      }
    }

    return -1; 
  }
};
