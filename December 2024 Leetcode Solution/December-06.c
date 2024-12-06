int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    bool hashSet[n + 1]; 
    memset(hashSet, 0, sizeof(hashSet));

    for (int i = 0; i < bannedSize; i++) {
        if (banned[i] <= n)
            hashSet[banned[i]] = true;
    }

    int ans = 0, sum = 0;

    for (int i = 1; i <= n; i++) {
        if (hashSet[i]) 
            continue;

        if (sum + i > maxSum)
            break;

        sum += i;
        ans++;
    }

    return ans;
}
