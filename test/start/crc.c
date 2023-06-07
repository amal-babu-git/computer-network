#include<stdio.h>
#include<stdlib.h>

int gp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int i, j, k, a[30], b[30],len, count=0;

void div1()
{
    for (i = 0; i < k; i++)
    {
        if (a[i] =gp[0])
        {
            for (j = i; j < 17 + i; j++)
            {
                a[i] ^= gp[count++];
            }
        }
        count = 0;
    }
}

int main(){

    printf("\nEnter the length of frame:");
    scanf("%d",&len);

    printf("\n Enter %d size message..\n",len);
    for(i=0;i<len;i++)
        scanf("%d",&a[i]);

    // add L-1 Os to the end
    for(i=0;i<16;i++)
        a[len++]=0;

    k=len-16;

    div1();

    for(i=0;i<len;i++){
        b[i]^=a[i];
    }
    printf("\nData transmitted----\n");
    for(i=0;i<len;i++)
        printf(" %d ",b[i]);

    printf("\nEnter the received data---\n");
    for(i=0;i<len;i++)
        scanf("%d",&a[i]);

    div1();

    for(i=0;i<len;i++){
        if(a[i]!=0){
            printf("Error\n");
            return 0;
        }
    }

    printf("\n Data received error free\n");
    
    return 0;

}