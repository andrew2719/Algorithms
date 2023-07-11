// matrix chain multiplication//
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Function to calculate the minimum number of scalar multiplications needed
// to compute the product of a chain of matrices
void matrixChainOrder(int p[], int n, int cost[MAX_SIZE][MAX_SIZE], int sequence[MAX_SIZE][MAX_SIZE])
{
    int i, j, k, L, q;

    // cost[i][j] represents the minimum number of scalar multiplications needed
    // to compute the product of matrices AiAi+1...Aj
    for (i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < cost[i][j])
                {
                    cost[i][j] = q;
                    sequence[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parenthesization of matrices in a chain
void printOptimalParenthesis(int sequence[MAX_SIZE][MAX_SIZE], int i, int j)
{
    if (i == j)
    {
        printf("a%d", i);
    }
    else
    {
        printf("(");
        printOptimalParenthesis(sequence, i, sequence[i][j]);
        printOptimalParenthesis(sequence, sequence[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n, p[MAX_SIZE], cost[MAX_SIZE][MAX_SIZE], sequence[MAX_SIZE][MAX_SIZE], i, j;

    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n, cost, sequence);

    printf("cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    printf("sequence matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", sequence[i][j]);
        }
        printf("\n");
    }

    printf("Optimal ordering is: ");
    printOptimalParenthesis(sequence, 1, n);
    printf("\n");

    printf("cost of matrix chain multiplication: %d\n", cost[1][n]);

    return 0;
}