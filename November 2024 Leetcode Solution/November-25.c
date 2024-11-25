#define QUEUE_SIZE 720

typedef struct {
    char state[7];
    int steps;
} Node;

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const char* goal = "123450";
    char start[7] = {0};
    char seen[QUEUE_SIZE][7] = {0}; 
    Node queue[QUEUE_SIZE];
    int front = 0, rear = 0;

    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardColSize[i]; ++j)
            start[i * boardColSize[i] + j] = '0' + board[i][j];

    if (strcmp(start, goal) == 0)
        return 0;

    strcpy(queue[rear].state, start);
    queue[rear++].steps = 0;
    strcpy(seen[rear - 1], start);

    while (front < rear) {
        Node curr = queue[front++];
        char state[7];
        strcpy(state, curr.state);
        int steps = curr.steps;
        int zeroIndex = strchr(state, '0') - state;
        int i = zeroIndex / 3;
        int j = zeroIndex % 3;

        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d][0];
            int y = j + dirs[d][1];
            if (x < 0 || x >= boardSize || y < 0 || y >= 3)
                continue;

            int swapIndex = x * 3 + y;
            char nextState[7];
            strcpy(nextState, state);
            char temp = nextState[zeroIndex];
            nextState[zeroIndex] = nextState[swapIndex];
            nextState[swapIndex] = temp;

            if (strcmp(nextState, goal) == 0)
                return steps + 1;

            bool alreadySeen = false;
            for (int k = 0; k < rear; ++k) {
                if (strcmp(seen[k], nextState) == 0) {
                    alreadySeen = true;
                    break;
                }
            }
            if (!alreadySeen) {
                strcpy(queue[rear].state, nextState);
                queue[rear++].steps = steps + 1;
                strcpy(seen[rear - 1], nextState);
            }
        }
    }

    return -1;
}
