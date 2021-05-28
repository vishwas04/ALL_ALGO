#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int found(char * t,char * p)
{
    int n=strlen(t);
    int m=strlen(p);

    for(int i=0;i<(n-m+1);i++)
    {
        int j=0;
        while (p[j]==t[i+j] && j<m)
        {
            j++;
        }
        if(j==m)
            return 1;
    }
    return 0;
}






int main()
{
    int m;
    int n;

    printf("LENGTH OF TEXT ?\n");
    scanf("%d",&n);
    char * t =malloc((sizeof(char)* n)+1);
    printf("ENTER TEXT\n");
    scanf("%s",t);

    printf("LENGTH OF PATTERN ?\n");
    scanf("%d",&m);
    char * p =malloc((sizeof(char)* m)+1);
    printf("ENTER PATTERN\n");
    scanf("%s",p);

    if(found(t,p))
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");
    
    free(t);
    free(p);
    t=NULL;
    p=NULL;


}