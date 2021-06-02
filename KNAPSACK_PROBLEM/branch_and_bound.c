#include<stdio.h> 

typedef struct
{
    int wt,val;
}item;
item a[50];

int max(int a, int b)
{ 
    return (a > b)? a : b;
} 

int knapSack(int W, int n) 
{ 
    if (n == 0 || W == 0) 
       return 0; 
   if (a[n-1].wt > W) 
       return knapSack(W, n-1); 
   else 
       return max( a[n-1].val + knapSack(W-a[n-1].wt, n-1), knapSack(W, n-1)); 
} 
  
int main() 
{ 
   
    int i,n,W;
    printf("Enter the Number of items and BAG SIZE \n");
    scanf("%d %d",&n,&W);
    printf("Enter weight and value of each object:\n");
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].val,&a[i].wt);
    printf("%d", knapSack(W, n)); 
    return 0; 
}