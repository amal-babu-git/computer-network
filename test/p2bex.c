#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n, pos;
    char a[20], b[50], ch;

    printf("Enter string: ");
    scanf("%s", &a);
    n = strlen(a);

    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > n)
    {
        printf("Invalid position\n");
        return 0;
    }

    printf("Enter character: ");
    scanf(" %c", &ch); // Add a space before %c to skip leading whitespace

    strcpy(b, "dlestx");
    j = 6;

    for (i = 0; i < n; i++)
    {
        if (i == pos - 1)
        {
            sprintf(b + j, "dle%cdle", ch);
            j += 6;
        }
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e')
        {
            sprintf(b + j, "dle");
            j += 3;
        }
        b[j++] = a[i];
    }

    strcpy(b + j, "dleetx");

    printf("\nFrame after stuffing:\n");
    printf("%s\n", b);

    return 0;
}
