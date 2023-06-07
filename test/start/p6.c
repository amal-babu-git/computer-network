#include <stdio.h>

int main()
{
    int ch, i;
    char str[100];

    printf("Enter a string:");
    scanf("%s", &str);

    printf("\n1.Encrypt\n2.Decrypt\nEnter choice:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        for (i = 0; (i < 100 && str[i] != '\0'); i++)
        {
            str[i] += 3;
        }
        printf("\n%s", str);
        break;

    case 2:
        for (i = 0; i < 100 && str[i] != '\0'; i++)
        {
            str[i] -= 3;
        }
        printf("\n%s", str);
    }
}