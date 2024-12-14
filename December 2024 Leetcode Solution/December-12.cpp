class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push((int)sqrt(top));
        }
        
        long long total = 0;
        while (!maxHeap.empty()) {
            total += maxHeap.top();
            maxHeap.pop();
        }
        return total;
    }
};
