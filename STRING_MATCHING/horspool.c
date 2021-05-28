#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int horspool_found(char * t,char * p)
{
    int n=strlen(t);
    int m=strlen(p);



    int shift_table[256];
    for (int i = 0; i < 256; i++)
    {
        shift_table[i]=m;
    }
    int i=0;
    while(p[i]!='\0' && i!=m-1)
    {
        shift_table[p[i]]=m-i-1;
        i++;
    }
     
   
    i = m-1;
    while (i < n)
    {
        int k=0;
        while (k<m && p[m-k-1]==t[i-k])
        {
            k++;
        }
        if(k==m)
            return 1;
        i=i+shift_table[t[i]];
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

    if(horspool_found(t,p))
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");
    
    free(t);
    free(p);
    t=NULL;
    p=NULL;


}