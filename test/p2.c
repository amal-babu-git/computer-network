#include <stdio.h>

void main()
{
    int a[50], b[50], i, j, count, k, n;

    printf("Enter the frame length:");
    scanf("%d", &n);

    printf("\nEnter input:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    i = j = 0;
    count = 1;

    while (i < n)
    {
        if (a[i] == 1)
        {
            b[j] = a[i];
            for (k = i + 1; k < n && a[k] == 1 && count < 5; k++)
            {
                b[++j] = a[k];
                count++;
                if (count == 5)
                {
                    b[++j] = 0;
                }
                i = k;
            }
            
        }
        else
        {
            b[j] = a[i];
        }
        i++;
        j++;
    }


    for ( i = 0; i < j ; i++)
    {
        printf("%d",b[i]);
    }
    
}