// Adjacencies MATRIX

//sample input
// 6 1 2 1 3 2 4 2 5 3 5 4 5 4 6 5 6 0 0 3 1
// nodes ... Source Destination Source Destination Source Destination ... start node
// 0 0 to stop Entering Source Destination

#include<stdio.h>
#include<stdlib.h>

void creategraph(int n,int a[][n+1])
{
    int i,j;
    while(1)
    {
    printf("Enter the source and destination ..");
    scanf("%d %d",&i,&j);
        
    if((i==0)&&(j==0))break;
        a[i][j]=1;
        a[j][i]=1;
    }
}


void am_dfs(int * visted,int n,int v,int a [][n+1])
{
    visted[v]=1;
    printf("%d -> ",v);
    for (int i=1 ; i<=n;i++)
    {
        if (visted[i]==0 && a[v][i]==1)
        {
            am_dfs(visted,n,i,a);
        }        
    }
    

}




int main()
{
    printf("ENTER THE NUMBER OF NODES\n");
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            a[i][j]=0;
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
    int visted[n+1];
    for (int i = 0; i < n+1; i++)
    {
        visted[i]=0;
    }
    int v;
    printf("Enter the start vertex for traversal");
	scanf("%d",&v);
	printf("\nThe graph traversed using DFS is ");
    am_dfs(visted,n,v,a);
    

}