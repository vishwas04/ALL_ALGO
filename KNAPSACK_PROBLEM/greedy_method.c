//NOT 0_1 KNAPSACK_PROBLEM
//i.e we can select an item in fration

#include<stdio.h>
#include<stdlib.h>


void knapsack(int * p,int * w,int n,int m)
{
    float p_by_w1[n];
    float p_by_w2[n];
    for (int i = 0; i < n; i++)
    {
        p_by_w1[i]=(float)p[i]/w[i];
        p_by_w2[i]=(float)p[i]/w[i];
        
    }
    float r[n];
    int x[n];
    for (int i = 0; i < n; i++)
    {
        r[i]=-1;
    }
    for (int k = 0; k < n; k++)
    {
        int max=0;
        for (int i = 1; i < n; i++)
        {
            if (p_by_w1[max] < p_by_w1[i])
            {
                max=i;
            }
        }
        
        if((m-w[max]) >= 0)
        {
            m=m-w[max];
            p_by_w1[max]=-1;
            r[k]=1;
            x[k]=max;
        }
        else
        {
       
            r[k]=(float)m/w[max];
            x[k]=max;
            break;
        }
    }
    printf("\n");
    float c=0;
    printf("OUTPUT\n");
    for (int i = 0; i < n; i++)
    {
        if (r[i]!=-1)
        {
            c=c+r[i]*p_by_w2[x[i]]*w[x[i]];
            printf("OBJECT %d -> %f x %f = %f\n",x[i]+1,r[i]*w[x[i]],p_by_w2[x[i]]*w[x[i]],r[i]*p_by_w2[x[i]]*w[x[i]]);
        }
    }
    printf("MAX PROFIT %f",c);
    
    
        
     
}
//7 10 2 5 3 15 5 7 7 6 1 18 4 3 1 15
int main()
{
    int n;
    printf("Enter the Number of items");
    scanf("%d",&n);
    int p[n+1];
    int w[n+1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d",i+1);
        scanf("%d",&p[i]);
        scanf("%d",&w[i]);
    }
    printf("BAG SIZE ");
    int m;
    scanf("%d",&m);
    knapsack(p,w,n,m);
    
}