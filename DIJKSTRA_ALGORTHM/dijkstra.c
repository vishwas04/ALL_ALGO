#include<stdio.h>
#include<stdlib.h>
//using prims and relaxation of other vertex when we select a vertex for min span tree

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
void relaxation(int selected,int n,int a[][n+1],int * output)
{
    for (int i = 1; i <=n ; i++)
    {
        if (a[selected][i])
        {
            if (output[selected]+a[selected][i] < output[i] )
            {
                output[i]=output[selected]+a[selected][i];
            }
            
        }
        
    }
    

}
void prims(int * selected,int n,int a[][n+1],int v)
{ 
    int output[n+1];
    for (int i = 1; i <= n+1; i++)
    {
        output[i]=99999999;
    }
    output[v]=0;
    int no_of_nodes_in_min_span=0;
    selected[v]=1;
    relaxation(v,n,a,output);
    while(no_of_nodes_in_min_span < n-1)
    {
        int x=0,y=0;
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
        if (min!=99999999)
        {
            printf("%d to %d with path %d\n",x,y,min);
        }
        
        relaxation(y,n,a,output);
        no_of_nodes_in_min_span++;
        
    }
    printf("\n");
    for (int i = 1; i <=n; i++)
    {
        if (output[i]==99999999)
        {
            printf("from %d to %d NO PATH\n",v,i);
        }
        else
            printf("from %d to %d Minimum Distance is %d\n",v,i,output[i]);
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
    int v;
    printf("Enter the source vertex");
    scanf("%d",&v);
    prims(selected,n,a,v);
}