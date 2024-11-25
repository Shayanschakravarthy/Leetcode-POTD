class Solution {
    public int slidingPuzzle(int[][] board) {

        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        String goal = "123450";
        StringBuilder start = new StringBuilder();

        for (int[] row : board) {
            for (int num : row) {
                start.append(num);
            }
        }

        if (start.toString().equals(goal)) {
            return 0;
        }

        Queue<String> queue = new ArrayDeque<>();
        Set<String> seen = new HashSet<>();
        queue.offer(start.toString());
        seen.add(start.toString());
        int steps = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String

 current = queue.poll();
                int zeroIndex = current.indexOf('0');
                int x = zeroIndex / 3;
                int y = zeroIndex % 3;

                for (int[] dir : dirs) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if (newX < 0 || newX >= 2 || newY < 0 || newY >= 3) continue;

                    int newZeroIndex = newX * 3 + newY;
                    char[] nextState = current.toCharArray();
                    nextState[zeroIndex] = nextState[newZeroIndex];
                    nextState[newZeroIndex] = '0';
                    String nextStateStr = new String(nextState);

                    if (nextStateStr.equals(goal)) {
                        return steps + 1;
                    }

                    if (!seen.contains(nextStateStr)) {
                        queue.offer(nextStateStr);
                        seen.add(nextStateStr);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}
