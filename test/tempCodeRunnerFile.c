#include <stdio.h>
#define max 3

void main()
{
    int a[max][max], path[max][max], t[max];
    int i, j, st = 0, ed = 0, stp, edp, min, p, index;

    printf("\n Enter the cost matrix...\n");
    for (i = 1; i <= max; i++)
    {
        for (j = 1; j <= max; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter num. paths:");
    scanf("%d", &p);

    printf("\nEnter paths...\n");
    for (i = 1; i <= p; i++)
    {
        for (j = 1; j <= max; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }

    // min
    for (i = 1; i <= p; i++)
    {
        stp = st;
        t[i] = 0;
        for (j = 1; j <= max; j++)
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