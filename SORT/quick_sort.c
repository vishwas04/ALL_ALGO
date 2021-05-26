#include<stdio.h>
#include<stdlib.h>

int main()
{
    int len=10;
    int * a = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {
        a[i]=rand();
    }
    bubble_sort(a,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    a=NULL;
}
