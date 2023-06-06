#include <stdio.h>
#include <string.h>

void main(){

    int a[20], b[30], i, j, k, count, n;
    printf("Enter frame length:");
    scanf("%d", &n);
    printf("\n Enter input frame 0s and 1s only:");
    for (i = 0; i < n; i++)
    {

        scanf("%d", &a[i]);
    }

    i = 0;
    count = 1;
    j = 0;
    while (i < n)
    {

        if (a[i] == 1)
        {
            b[j] = a[i];
            for (k = i + 1; a[k] == 1 && k < n && count < 5; k++)
            {
                b[++j] = a[k];
                count++;
                if (count == 5)
                {
                    b[++j] = 0;
                    // FIXME: updating count variable,  fix by me
                    count=0;
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
    printf("\n After stuffing the frame\n");
    for (i = 0; i < j; i++)
    {

        printf("%d", b[i]);
    }
}
