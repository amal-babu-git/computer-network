#include <stdio.h>
#define L 17
int a[100], b[100], i, j, len, k, count = 0;
int gp[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
// int gp[] = {1, 0, 1};

int main()
{
    void div();

    printf("\n Enter the length of data frame: ");
    scanf("%d", &len);

    printf("\n Enter the message: ");
    for (i = 0; i < len; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < L-1; i++)
        a[len++] = 0;

    k = len - L-1;

    div();

    for (i = 0; i < len; i++)
        b[i] = b[i] ^ a[i];

    printf("\n Data to be transmitted: ");
    for (i = 0; i < len; i++)
        printf("%2d", b[i]);

    printf("\n\n Enter the received data: ");
    for (i = 0; i < len; i++)
        scanf("%d", &a[i]);

    div();

    for (i = 0; i < len; i++)
        if (a[i] != 0)
        {
            printf("\n ERROR in received data");
            return 0;
        }
        
    printf("\n Data received is ERROR FREE");
}

void div()
{
    for (i = 0; i < k; i++)
    {
        if (a[i] = gp[0])
        {
            for (j = i; j < L + i; j++)
                a[j] = a[j] ^ gp[count++];
        }
        count = 0;
    }
}
