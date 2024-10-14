#include <stdio.h>

// Function to return the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Initialize the DP table to 0
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            K[i][w] = 0;
        }
    }

    // Build the table K[][] in bottom-up manner
    printf("\nBuilding the table step by step:\n\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Initialize the first row and column to 0
            } else if (wt[i - 1] <= w) {
                // Include the item or exclude it and take the max value
                if (val[i - 1] + K[i - 1][w - wt[i - 1]] > K[i - 1][w]) {
                    K[i][w] = val[i - 1] + K[i - 1][w - wt[i - 1]];
                } else {
                    K[i][w] = K[i - 1][w];
                }
            } else {
                K[i][w] = K[i - 1][w]; // Exclude the item
            }
        }

        // Print the current state of the DP table after each item
        if (i > 0) {
            printf("After considering item %d (weight=%d, value=%d):\n", i, wt[i - 1], val[i - 1]);
        } else {
            printf("After considering item %d (weight=0, value=0):\n", i);
        }

        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= W; y++) {
                printf("%4d ", K[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return K[n][W]; // Maximum value that can be achieved
}

int main() {
    int n, W;

    // Get the number of items from the user
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    // Get the values and weights of each item from the user
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    // Get the maximum capacity of the knapsack
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function and display the result
    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));

    return 0;
}


/*In the printf statement where I previously used the ternary operator to check if the 
item is 0, I replaced it with a regular if-else statement. This checks if i > 0 and 
prints the appropriate weight and value for the item. If i == 0, it prints weight and 
value as 0.
*/