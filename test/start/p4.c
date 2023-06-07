#include <stdio.h>

int main()
{
    int i, frame[30], w, f;
    printf("\nEnter the window size:\n");
    scanf("%d", &w);

    printf("\nEnter num. of frames\n");
    scanf("%d", &f);

    printf("\nEnter %d frames\n", f);
    for (i = 1; i <= f; i++)
    {
        scanf("%d", &frame[i]);
    }

    printf("\n after sending %d frames waits for ack\n", w);
    for (i = 1; i <= f; i++)
    {
        if (i % w == 0)
        {
            printf("\n%d", frame[i]);
            printf("\nAck above frame send by the sender\n");
        }
        else
        {
            printf("\n%d", frame[i]);
        }
    }

    if (f % w != 0)
    {
        printf("\nAck of above frame send is received by the sender\n");
    }

    return 0;
}