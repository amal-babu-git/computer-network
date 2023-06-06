#include<stdio.h>
#include<string.h>
#include<process.h>

int main(){
    int i=0,j=0,pos,n;
    char a[20], b[50], ch;

    printf("Enter the string, char and position\n");
    scanf("%s %c %d",&a,&ch,&pos);

    n=strlen(a);
    sprintf(b,"dlestx");
    j+=6;

    while(i<n){
        if(i== pos-1){
            sprintf(b+j,"dle%cdle",ch);
            j+=7;
        }
        if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e'){
            sprintf(b+j,"dle");
        }
        b[j]=a[i];
        j++;
        i++;
    }
    sprintf(b+j,"dleetx");
    printf("\n %s",b);

    return 0;

}