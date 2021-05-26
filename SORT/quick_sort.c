#include<stdio.h>
#include<stdlib.h>

int partition(int * a,int start,int end)
{
    int i=start+1,j=end-1;
    int p = a[start];
    while (i<=j)
    {
        
        while (i<=end && a[i]<=p)
        {
            i++;
        }
        while (j>start && a[j]>=p)
        {
            j--;
        }
        if (i < j) 
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        
    }
    if(j!=start)
    {
        a[start]=a[j];
        a[j]=p;
    }
    return j;
}

void quick_sort(int * a,int start,int end)
{
    if(start < end)
    {
    int j=partition(a,start,end);
    quick_sort(a,start,j-1);
    quick_sort(a,j+1,end);

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
    quick_sort(a,0,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    a=NULL;
}
