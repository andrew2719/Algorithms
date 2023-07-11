// optimal binary search
#include <stdio.h>
struct mat
{
    int w, c, r;
};
int arr[100], n;
int mind(int arr[], int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}
int print(struct mat a[][n + 1], int i, int j)
{
    printf("Left child of %d is :: %d\n", a[i][j].r, a[i][a[i][j].r - 1].r);
    printf("Right child of %d is :: %d\n", a[i][j].r, a[a[i][j].r][j].r);
    if (a[i][a[i][j].r - 1].r != 0)
    {
        print(a, i, a[i][j].r - 1);
    }
    if (a[a[i][j].r][j].r != 0)
    {
        print(a, a[i][j].r, j);
    }
}
int main()
{
    int i, j, k;
    scanf("%d", &n);
    int b[n], c[n + 1];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    int l = n;
    struct mat a[n + 1][n + 1];
    for (int d = 0; d <= n; d++)
    {
        for (i = 0; i <= n; i++)
        {
            j = i + d;
            if (j <= n)
            {
                if (i == j)
                {
                    a[i][j].w = c[i];
                    a[i][j].c = 0;
                    a[i][j].r = 0;
                }
                else
                {
                    a[i][j].w = a[i][j - 1].w + b[j - 1] + c[j];
                    int n1 = (i - j), k = 0;
                    for (int n2 = i + 1; n2 <= j; n2++)
                    {
                        arr[k++] = a[i][n2 - 1].c + a[n2][j].c;
                    }
                    printf("\n");
                    a[i][j].c = arr[mind(arr, k)] + a[i][j].w;
                    a[i][j].r = mind(arr, k) + i + 1;
                }
            }
        }
    }
    printf("Optimal BST is :: w values are:\n");
    for (int diff = 0; diff <= n; diff++)
    {
        for (i = 0; i <= n; i++)
        {
            j = i + diff;
            if (j <= n)
            {
                printf("%d ", a[i][j].w);
            }
        }
        printf("\n");
    }
    printf("c values are:\n");
    for (int diff = 0; diff <= n; diff++)
    {
        for (i = 0; i <= n; i++)
        {
            j = i + diff;
            if (j <= n)
            {
                printf("%d ", a[i][j].c);
            }
        }
        printf("\n");
    }
    printf("r values are:\n");
    int x, y;
    for (int diff = 0; diff <= n; diff++)
    {
        for (i = 0; i <= n; i++)
        {
            j = i + diff;
            if (j <= n)
            {
                printf("%d ", a[i][j].r);
                x = i;
                y = j;
            }
        }
        printf("\n");
    }
    printf("Root is %d\n", a[x][y].r);
    print(a, x, y);
}