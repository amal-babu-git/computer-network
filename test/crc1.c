#include <stdio.h>

int a[30], b[30];
int i, j, count = 0, k, len;
int gp[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
void div();

int main(){
    printf("Enter the length of frame:");
    scanf("%d",&len);

    // accepting frame
    printf("\nEnter %d frames\n",len);
    for(i=0;i<len;i++)
        scanf("%d",&a[i]);

    // add L-1 i.e, 16 0s to the end
    for(i=0;i<16;i++)
        a[len++]=0;

    // length of a[]
    k=len-16;

    // XOR division
    div();

    // b[] xor with a[]
    for ( i = 0; i < len; i++)
    {
        b[i]^=a[i];
    }

    printf("\n----Data transmitted----------\n");
    for ( i = 0; i < len; i++)
    {
        printf(" %d ",b[i]);
    }

    printf("\nEnter the received data---\n");
    for(i=0;i<len;i++){
        scanf("%d",&a[i]);
    }
    // perform div operation (XOR)
    div();

    for ( i = 0; i < len; i++)
    {
        if(a[i]!=0){
            printf("\n-ERROR-\n");
            return 0;
        }
    }
    printf("\nData received error free\n");
    
    return 0;
}

void div(){
    for ( i = 0; i < k; i++)
    {
        if(a[i]=gp[0]){
            for ( j = i; j < 17+i; j++)
            {
                a[j]^=gp[count++];
            }
            
        }
        count=0;
    }
    
}
