long long pickGifts(int* gifts, int giftsSize, int k) {
    for (int i = (giftsSize - 2) / 2; i >= 0; i--) {
        int current = i;
        while (current * 2 + 1 < giftsSize) {
            int child = current * 2 + 1;
            if (child + 1 < giftsSize && gifts[child] < gifts[child + 1]) {
                child++;
            }
            if (gifts[current] >= gifts[child]) {
                break;
            }
            int temp = gifts[current];
            gifts[current] = gifts[child];
            gifts[child] = temp;
            current = child;
        }
    }

    for (int i = 0; i < k; i++) {
        gifts[0] = (int)sqrt(gifts[0]);
        int current = 0;
        while (current * 2 + 1 < giftsSize) {
            int child = current * 2 + 1;
            if (child + 1 < giftsSize && gifts[child] < gifts[child + 1]) {
                child++;
            }
            if (gifts[current] >= gifts[child]) {
                break;
            }
            int temp = gifts[current];
            gifts[current] = gifts[child];
            gifts[child] = temp;
            current = child;
        }
    }

    long long sum = 0;
    for (int i = 0; i < giftsSize; i++) {
        sum += gifts[i];
    }
    return sum;
}
