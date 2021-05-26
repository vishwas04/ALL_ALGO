#include<stdio.h>
#include<stdlib.h>
void selection_sort(int * a,int len)
{
    int min,t;
    for(int i =0 ; i<len;i++)
    {
        min=i;
        for (int j = i+1; j < len; j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        
        if(min != i)
        {
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
        
    }
}


int main()
{
    int len=10;
    int * a = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {
        a[i]=rand();
    }
    selection_sort(a,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
}