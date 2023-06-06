#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j,k,count,a[30],b[30],n;

    printf("Enter the number of frames ");
    scanf("%d",&n);

    printf("\n Enter %d frames \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    i=0; 
    j=0; 
    count=1;

    while(i<n){
        if(a[i]==1){
            b[j]=a[i];

            for(k=i+1;a[k]==1 && k < n && count < 5 ; k++){
                b[++j]=a[k];
                count++;
                
                if(count == 5){
                    b[++j]=0;
                    count=0;
                }
                i=k;
            }

        }else{
            b[j]=a[i];
        }
        i++;
        j++;
    }

    printf("\nAfter bit stuffing\n");
    for(i=0;i<j;i++){
        printf("%d ",b[i]);
    }

    return 0;

}