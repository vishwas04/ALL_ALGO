#include<stdio.h>
#include<stdlib.h>
# define MAX 10 //   =< len

int q[MAX];
int count=0;

void add(int * q,int d)
{
    if(count==MAX)
    {
        printf("Queue is full");
        return;
    }

    int x;
    x=d;
    q[count]=x;
    count++;
    int i=count-1;
    int j=(i-1)/2;
    while (i>0 && q[j] > x)
    {
        q[i]=q[j];
        i=j;
        j=(i-1)/2;
    }
    q[i]=x;
    
}



void adjust(int * q)
{ 
     int i,j=0;
     int key;

     key=q[0];
     i=1;
      
     while(i<=count-1)
     {
      if((i+1)<=count-1)
      {
        if(q[i+1]<q[i])
           i++;//get the index of the smallest child
      }
       if(key > q[i])
       {
            q[j]=q[i]; //move the child up
            j=i;
            i=2*j+1;
       }
       else
          break;
      }
      q[j]=key; 
}



int delete(int * q)
{
    if(count==0)
    {
        printf("EMPTY\n");
        return -999;
    }
    int temp;
    temp=q[0];
    q[0]=q[count-1];
    (count)--;
    adjust(q);
    return temp;
}




void heap_sort(int * a,int len)
{
    for (int i=0;i<len;i++)
    {
        add(q,a[i]);
    }
    for (int i = 0; i < len; i++)
    {
        a[i]=delete(q);
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
    heap_sort(a,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
    free(a);
    a=NULL;
}