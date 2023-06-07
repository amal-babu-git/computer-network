#include <stdio.h>
#include <string.h>
#include <process.h>

int main()
{
    int i, j, n, pos;
    char a[50], b[50], ch;

    printf("Enter the string position and char:");
    scanf("%s %d %c", &a, &pos, &ch);
    printf("\n%s %d %c\n",a,pos,ch);
    
    n = strlen(a);
    i = 0;
    j = 0;
    sprintf(b, "dlestx");
    j += 6;

    while (i < n)
    {
        if (i == pos - 1)
        {
            sprintf(b + j, "dle%cdle", ch);
            j += 7;
        }
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e')
        {
            sprintf(b + j, "dle");
            j += 3;
        }
        b[j] = a[i];
        i++;
        j++;
    }
    sprintf(b+j,"dleetx\0");
    printf("\nAfter character stuffing---\n");

    printf("\n%s", b);

    return 0;
}