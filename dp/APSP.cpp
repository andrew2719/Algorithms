#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n], i, j, k, l = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
            {
                a[i][j] = 999;
            }
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                l = a[i][k] + a[k][j];
                a[i][j] = a[i][j] < l ? a[i][j] : l;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i][i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
        
    }
}