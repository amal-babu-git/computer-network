#include <stdio.h>
void main()
{
    int path[5][5], i, j, min, a[5][5], p, st = 1, ed = 5, stp, edp, t[5], index;
    printf("Enter the cost matrix\n");
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the number of paths\n");
    scanf("%d", &p);

    printf("Enter possible paths\n");
    for (i = 1; i <= p; i++)
        for (j = 1; j <= 5; j++)
            scanf("%d", &path[i][j]);

    // find cost
    for (i = 1; i <= p; i++)
    {
        t[i] = 0;
        stp = st;
        for (j = 1; j <= 5; j++)
        {
            edp = path[i][j + 1];
            t[i] = t[i] + a[stp][edp];
            if (edp == ed)
                break;
            else
                stp = edp;
        }
    }
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
    printf("Minimum cost %d", min);
    printf("\n Minimum cost path ");
    for (i = 1; i <= 5; i++)
    {
        printf("--> %d", path[index][i]);
        if (path[index][i] == ed)
            break;
    }
}
