class Solution {
    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, Deque<Integer>> adjacencyList = new HashMap<>();
        Map<Integer, Integer> degree = new HashMap<>();

        for (int[] pair : pairs) {
            adjacencyList.computeIfAbsent(pair[0], k -> new ArrayDeque<>()).addLast(pair[1]);
            degree.put(pair[0], degree.getOrDefault(pair[0], 0) + 1);
            degree.put(pair[1], degree.getOrDefault(pair[1], 0) - 1);
        }

        int startNode = pairs[0][0];
        for (int node : degree.keySet()) {
            if (degree.get(node) == 1) {
                startNode = node;
                break;
            }
        }

        List<Integer> path = new ArrayList<>();
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(startNode);

        while (!stack.isEmpty()) {
            while (!adjacencyList.getOrDefault(stack.peek(), new ArrayDeque<>()).isEmpty()) {
                stack.push(adjacencyList.get(stack.peek()).pollLast());
            }
            path.add(stack.pop());
        }

        int[][] result = new int[pairs.length][2];
        for (int i = path.size() - 1, j = 0; i > 0; i--, j++) {
            result[j] = new int[]{path.get(i), path.get(i - 1)};
        }

        return result;
    }
}
