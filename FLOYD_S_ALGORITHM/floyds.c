#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//9 1 2 3 1 6 5 1 5 6 2 6 4 2 3 1 3 4 6 3 6 4 4 6 5 4 5 8 5 6 2 7 8 2 7 9 3 0 0 0 
//SAMPLE OUTPUT
int min(int x,int y)
{
    if (x < y)
    {
        return x;
    }
    return y;
    
}
void floyds(int n,int a[][n+1])
{
    int A[n+1][n+1][n+1];
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            A[0][i][j]=a[i][j];
        }
    }

    for (int k = 1; k<=n; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j<= n; j++)
            {
                if (i!=j)
                {
                    A[k][i][j]=min(A[k-1][i][j],A[k-1][i][k]+A[k-1][k][j]);
                }
                else
                {
                A[k][i][j] =0;
                }
            }
        }
    }
    

    printf("\nOUTPUT\n");
    for (int i = 1; i <= n; i++)
    {
        printf("a[%d] -> ",i);
        for (int j = 1; j <=n; j++)
        {
            if (A[n][i][j]==9999)
            {
                printf("- ");
            }
            else
            printf("%d ",A[n][i][j]);
        }
        
        printf("\n");
    }
    
}
 void creategraph(int n,int a[][n+1])
{
    int i,j,w;
    while(1)
    {
    printf("Enter the source destination path length");
    scanf("%d%d%d",&i,&j,&w);
        
    if((i==0)&&(j==0))break;
        a[i][j]=w;
        //a[j][i]=w; //DIRECTED OR NON DIRECTED
    }
}

int main()
{
    printf("%d",INT_MAX);
    printf("ENTER THE NUMBER OF NODES\n");
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i==j)
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=9999;
            }
            
        }
        
        printf("\n");
    }
    creategraph(n,a);

    printf("\n");

    for (int i = 1; i <= n; i++)
    {
        printf("a[%d] -> ",i);
        for (int j = 1; j <=n; j++)
        {
            printf("%d ",a[i][j]);
        }
        
        printf("\n");
    }
    floyds(n,a);
}