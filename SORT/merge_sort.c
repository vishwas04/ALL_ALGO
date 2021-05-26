#include<stdio.h>
#include<stdlib.h>
void merge(int * a,int start,int mid,int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    int l[n1];
    int r[n2];
    for (int i=0;i<n1;i++)
    {
        l[i]=a[start+i];
    }
    for (int i=0;i<n2;i++)
    {
        r[i]=a[mid+i+1];
    }
    int i=0,j=0,k=start;
    while (i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k]=l[i];
        k++;i++;
    }
    while (j<n2)
    {
        a[k]=r[j];
        k++;j++;
    }
    
    

}




void merge_sort(int * a,int start,int end)
{
    if(end > start)
    {
        int mid=start+(end-start)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,1,mid,end);
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
    merge_sort(a,0,len-1); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    a=NULL;
}