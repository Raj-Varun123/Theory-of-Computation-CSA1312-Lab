#include <stdio.h>

#define MAX_STATES 10

int main() {
    int n, epsilon_transitions[MAX_STATES][MAX_STATES], i, j;

    printf("Enter the number of states in the NFA: ");
    scanf("%d", &n);

    printf("Enter the epsilon transitions matrix (1 if e-move exists from state i to j, else 0):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &epsilon_transitions[i][j]);
        }
    }

    printf("\ne-closure of each state:\n");
    for (i = 0; i < n; i++) {
        int closure[MAX_STATES] = {0};
        int stack[MAX_STATES], top = -1;

        // Initialize closure with the state itself
        closure[i] = 1;
        stack[++top] = i;

        // Perform DFS to find all reachable states via e-moves
        while (top >= 0) {
            int state = stack[top--];
            for (j = 0; j < n; j++) {
                if (epsilon_transitions[state][j] && !closure[j]) {
                    closure[j] = 1;
                    stack[++top] = j;
                }
            }
        }

        // Print e-closure of state i
        printf("e-closure(%d) = { ", i);
        for (j = 0; j < n; j++) {
            if (closure[j])
                printf("%d ", j);
        }
        printf("}\n");
    }

    return 0;
}
