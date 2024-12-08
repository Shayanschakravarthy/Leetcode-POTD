int cmpEvents(const void *a, const void *b) {
    const int *eventA = *(const int **)a;
    const int *eventB = *(const int **)b;
    return eventA[0] - eventB[0];
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize) {
    qsort(events, eventsSize, sizeof(events[0]), cmpEvents);

    int *suffixMax = (int *)malloc(eventsSize * sizeof(int));
    suffixMax[eventsSize - 1] = events[eventsSize - 1][2]; 

    for (int i = eventsSize - 2; i >= 0; --i) {
        suffixMax[i] = (events[i][2] > suffixMax[i + 1]) ? events[i][2] : suffixMax[i + 1];
    }

    int maxResult = 0;

    for (int i = 0; i < eventsSize; ++i) {
        int currentValue = events[i][2];
        int left = i + 1, right = eventsSize - 1;
        int end = events[i][1];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > end) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < eventsSize) {
            currentValue += suffixMax[left];
        }
        if (currentValue > maxResult) {
            maxResult = currentValue;
        }
    }

    free(suffixMax); 
    return maxResult;
}
