typedef struct {
    int time, row, col;
} Node;

typedef struct {
    Node* data;
    int size, capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (Node*)malloc(capacity * sizeof(Node));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue* pq, Node node) {
    if (pq->size == pq->capacity) return;
    pq->data[pq->size] = node;
    int i = pq->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->data[parent].time <= pq->data[i].time) break;
        swap(&pq->data[parent], &pq->data[i]);
        i = parent;
    }
}

Node pop(PriorityQueue* pq) {
    Node top = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    int i = 0;
    while (true) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < pq->size && pq->data[left].time < pq->data[smallest].time) smallest = left;
        if (right < pq->size && pq->data[right].time < pq->data[smallest].time) smallest = right;
        if (smallest == i) break;
        swap(&pq->data[i], &pq->data[smallest]);
        i = smallest;
    }
    return top;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int minimumTime(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool** seen = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        seen[i] = (bool*)calloc(cols, sizeof(bool));
    }

    PriorityQueue* pq = createPriorityQueue(rows * cols);
    push(pq, (Node){0, 0, 0});
    seen[0][0] = true;

    while (!isEmpty(pq)) {
        Node current = pop(pq);
        int time = current.time, row = current.row, col = current.col;

        for (int d = 0; d < 4; d++) {
            int newRow = row + dirs[d][0], newCol = col + dirs[d][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !seen[newRow][newCol]) {
                int newTime = time + 1;
                if (grid[newRow][newCol] > newTime) {
                    newTime += (grid[newRow][newCol] - newTime + 1) / 2 * 2;
                }
                if (newRow == rows - 1 && newCol == cols - 1) {
                    for (int i = 0; i < rows; i++) free(seen[i]);
                    free(seen);
                    free(pq->data);
                    free(pq);
                    return newTime;
                }
                seen[newRow][newCol] = true;
                push(pq, (Node){newTime, newRow, newCol});
            }
        }
    }

    for (int i = 0; i < rows; i++) free(seen[i]);
    free(seen);
    free(pq->data);
    free(pq);

    return -1;
}
