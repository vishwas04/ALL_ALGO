#include<stdio.h>
#include<stdlib.h>
int max(int x,int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
    
}

void knapsack(int * p,int * w,int n,int m)
{
    //sort
    int min,t;
    for(int i =0 ; i<n;i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
            if(w[min]>w[j])
            {
                min=j;
            }
        }
        
        if(min != i)
        {
            t=w[min];
            w[min]=w[i];
            w[i]=t;
            t=p[min];
            p[min]=p[i];
            p[i]=t;
        }
        
    }




    int v[n+1][m+1];
    for (int i = 0; i <= m; i++)
    {
        v[0][i]=0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j-w[i-1] >= 0)
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i-1]]+p[i-1]);
            else
                v[i][j]=v[i-1][j];
        }
        
    }

    
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    
    printf("\n%d",v[n][m]);
}

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