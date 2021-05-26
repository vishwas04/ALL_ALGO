#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int * a,int len)
{
    int t;
    int j;
    for (int i = 1; i < len; i++)
    {
        
        t=a[i];
        int q=0;
        for (j = i-1 ; j >= 0; j--)
        {   
            
            if (a[j] > t)
            {
                q=1;
                a[j+1]=a[j];
            }
            else
                break;
        }
        if(q)
            a[j+1]=t;
        
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
    insertion_sort(a,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    a=NULL;
}