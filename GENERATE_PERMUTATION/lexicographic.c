#include<stdio.h>
#include<stdlib.h>
//for sorting Quick sort is used
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

void lexicographic(int n)
{
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=i+1;
    }
    int i;
    while (1)
    {
        for (int x = 0; x < n; x++)
        {
            printf("%d ",a[x]);
        }
        printf("\n");

        for (i = n-1; i > 0; i--)
        {
            if (a[i-1] < a[i])
            {
                break;
            }
        }
        
        if (i==0)
        {
            break;
        }
        i=i-1;
        int j=i+1;
        int min=j;
        while (j<n)
        {
            if (a[j] > a[i] && a[j]<a[min])
            {
                min=j;
            }
            j++;
        }
        int t=a[min];
        a[min]=a[i];
        a[i]=t;
        quick_sort(a,i+1,n);
        
        
    }
    
    
}


int main()
{
    printf("n-");
    int n;
    scanf("%d",&n);
    lexicographic(n);
}