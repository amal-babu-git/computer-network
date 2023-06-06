#include <stdio.h>

void main()
{
    int a[6][6], path[6][6], t[6];
    int i, j, st = 1, ed = 5, stp, edp, min, p, index;

    printf("\n Enter the cost matrix...\n");
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter num. paths:");
    scanf("%d", &p);

    printf("\nEnter paths...\n");
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
        stp = st;
        t[i] = 0;
        for (j = 1; j <= 5; j++)
        {
            edp = path[i][j + 1];
            t[i] += a[stp][edp];

            if (edp == ed)
            {
                break;
            }
            else
            {
                stp = edp;
            }
        }
    }

    // min t[]
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

    printf("\nShortest path:\n");
    for (i = 1; i <= 5; i++)
    {
        printf("-->%d", path[index][i]);
        if (path[index][i] == ed)
            break;
    }
    printf("\n Minimum cost: %d\n", min);
}
