class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int j = 0;

        for (int i = 0; i < n; ++i) {
            if (start[i] != '_') {
                while (j < n && target[j] == '_') j++;

                if (j == n || start[i] != target[j]) return false;

                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;

                j++;
            }
        }

        while (j < n) {
            if (target[j] != '_') return false;
            j++;
        }

        return true;
    }
};
