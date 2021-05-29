// Adjacencies MATRIX

//sample input
// 6 1 2 1 3 2 4 2 5 3 5 4 5 4 6 5 6 0 0 3 1
// nodes ... Source Destination Source Destination Source Destination ... start node
// 0 0 to stop Entering Source Destination


#include<stdio.h>
#include<stdlib.h>




//QUEUE OPERATION

int f=-1,r=-1; 
void qinsert(int v,int * q)
{   
    if((f==-1)&&(r==-1)) f++;
    	q[++r]=v;
		
}

int qdelete(int * q)
{
	int w;
	w=q[f];
	if(f==r) {f=-1;r=-1;}
	else f++;
	return w;
}

int qisempty()
{
	if((f==-1) && (r==-1))return 1;
	else return 0;
}



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


void am_bfs(int * visted,int n,int v,int a [][n+1],int * q)
{
    qinsert(v,q);
    visted[v]=1;
    while (qisempty()!=1)
    {
        v=qdelete(q);
        printf("%d ->",v);
        for (int i = 1; i <= n; i++)
        {
            if (a[v][i]==1 && visted[i]==0)
            {
                qinsert(i,q);
                visted[i]=1;
            }
            
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
    int q[n+1];
    am_bfs(visted,n,v,a,q);
    

}