class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int gift : gifts) {
            maxHeap.offer(gift);
        }
        
        for (int i = 0; i < k; i++) {
            int top = maxHeap.poll();
            maxHeap.offer((int)Math.sqrt(top));
        }
        
        long total = 0;
        while (!maxHeap.isEmpty()) {
            total += maxHeap.poll();
        }
        return total;
    }
}
