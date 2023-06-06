#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
void main()
{
    int i = 0, j = 0, n, pos;
    char a[20], b[50], ch;

    printf("enter string\n");
    scanf("%s", &a);
    n = strlen(a);
    printf("enter position\n");
    scanf("%d", &pos);
    if (pos > n)
    {
        printf("invalid position, Enter again :");
        scanf("%d", &pos);
    }
    printf("enter the character\n");
    ch = getch();

    sprintf(b, "dlestx");
    j = 6;
    while (i < n)
    {
        if (i == pos - 1)
        {
            sprintf(b + j, "dle%cdle", ch);
            j = j + 7;
        }
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e')
        {
           
            sprintf(b + j, "dle");
            j = j + 3;
        }

        b[j] = a[i];
        i++;
        j++;
    }
   
    sprintf(b + j, "dleetx\0");
    printf("\nframe after stuffing:\n");
    printf("%s", b);
    getch();
}