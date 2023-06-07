#include<stdio.h>

void main(){
    int a[10],b[10],i,j,count,k,n;

    printf("\n Enter the length:\n");
    scanf("%d",&n);

    printf("\nEnter %d size message\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    i=j=0;
    count=1;

    while(i<n){
        if(a[i]==1){
            b[j]=a[i];

            for(k=i+1; a[k]==1 && k<n && count <5 ; k++){
                b[++j]=a[k];
                count++;
                if(count==5){
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
        printf(" %d ",b[i]);
    }

}