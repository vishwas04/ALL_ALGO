#include<stdio.h>
#include<stdlib.h>

//SAMPLE INPUT
//6 1 2 3 1 6 5 1 5 6 2 6 4 2 3 1 3 4 6 3 6 4 4 6 5 4 5 8 5 6 2 0 0 0

void creategraph(int n,int a[][n+1])
{
    int i,j,w;
    while(1)
    {
    printf("Enter the source destination path length");
    scanf("%d%d%d",&i,&j,&w);
        
    if((i==0)&&(j==0))break;
        a[i][j]=w;
        a[j][i]=w;
    }
}
void prims(int * selected,int n,int a[][n+1])
{ 
    int no_of_nodes_in_min_span=0;
    while(no_of_nodes_in_min_span < n-1)
    {
        int x=0,y=0;
        selected[1]=1;
        int min=99999999;
        for (int i = 1; i <= n; i++)
        {
            if(selected[i])
            {
                //FIND THE MIN NODE FROM ALL SELECTED NODE
                for (int j = 1; j <=n; j++)
                {
                    if (selected[j]==0 && a[i][j])
                    {
                        if (min > a[i][j])
                        {
                            min=a[i][j];
                            x=i;
                            y=j;
                        }
                        
                    }
                    
                }
                
            }
        }
        selected[y]=1;
        printf("%d to %d with path %d\n",x,y,min);
        no_of_nodes_in_min_span++;
        
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
    int selected[n+1];
    for (int i = 0; i < n+1; i++)
    {
        selected[i]=0;
    }
    printf("\nmin span tree-\n");
    prims(selected,n,a);
}