#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int * a,int len)
{
    int i, j,temp; 
   int swapped; 
   for (i = 0; i < len-1; i++) 
   { 
     swapped = 0; 
     for (j = 0; j < len-i-1; j++) 
     { 
        if (a[j] > a[j+1]) 
        { 
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
           swapped = 1; 
        } 
     } 
  
     if (swapped == 0) 
        break; 
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
    bubble_sort(a,len); 
    for (int i = 0; i < len; i++)
    {
        printf("%d\n",a[i]);
    }
}