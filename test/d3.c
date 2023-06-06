#include <stdio.h>

void main()
{
    int a[10][10], t[10], i, j, p, min, path[10][10], stp, edp, st = 1, ed = 5, index;

    printf("---Enter cost matrix---\n");
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter num. of paths:");
    scanf("%d", &p);
    printf("\nEnter paths-------\n");
    for (i = 1; i <= p; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }

    // min
    for (i = 1; i <= p; i++)
    {
        t[i] = 0;
        stp = st;
        for (j = 1; j <= 5; j++)
        {
            edp = path[i][j + 1];
            t[i] += a[stp][edp];
            if (edp == ed)
                break;
            else
                stp = edp;
        }
    }

    // min
    min = t[st];
    index = st;
    for (i = 1; i <= p; i++)
    {
        if (min > t[i])
        {
            min = t[i];
            index = i;
        }
    }

    printf("\n Min cost: %d\n", min);
    printf("\n--paths--\n");
    for (i = 1; i <= 5; i++)
    {
        printf("-->%d", path[index][i]);
        if (path[index][i] == ed)
            break;
    }
}