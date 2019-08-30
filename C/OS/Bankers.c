#include <stdio.h>

#define MAX_PROC 10
#define MAX_RES 10

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int n, m, i, j, k;
    n = 5;
    m = 3;
    int alloc[MAX_RES][MAX_PROC] = {{0, 1, 0},
                                    {2, 0, 0},
                                    {3, 0, 2},
                                    {2, 1, 1},
                                    {0, 0, 2}};

    int max[MAX_RES][MAX_PROC] = {{7, 5, 3},
                                  {3, 2, 2},
                                  {9, 0, 2},
                                  {2, 2, 2},
                                  {4, 3, 3}};

    int avail[3] = {3, 3, 2};

    int f[n], ans[n], ind = -1;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                        flag = 1;
                    break;
                }
                if (flag == 0)
                {
                    ans[++ind] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the Safe Sequence\n");
    for (i = 0; i < 4; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);

    return (0);
}