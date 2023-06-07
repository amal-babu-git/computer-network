#include<stdio.h>

int main(){
    int a[10][10], t[10], path[10][10];
    int i, j, stp, edp, st=1,ed=5, p,min,index;

    printf("\n Enter the cost matrix:\n");
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter num. of paths:");
    scanf("%d",&p);

    printf("\nEnter the paths...\n");
    for(i=1;i<=p;i++){
        for(j=1;j<=5;j++){
            scanf("%d",&path[i][j]);
        }
    }

    // find min cost paths
    for(i=1;i<=p;i++){
        t[i]=0;
        stp=st;

        for(j=1;j<=5;j++){
            edp=path[i][j+1];
            t[i] = t[i]+ a[stp][edp];
            if(edp==ed)
                break;
            else
                stp=edp;
        }
    }

    min=t[st];
    index=st;
    for(i=1;i<=p;i++){
        if(min > t[i]){
            min=t[i];
            index=i;
        }
    }

    printf("\nMin cost %d",min);

    for ( i = 1; i <= 5; i++)
    {
        printf("-->%d",path[index][i]);
        if(path[index][i]==ed)
            break;
    }

    return 0;
    
}