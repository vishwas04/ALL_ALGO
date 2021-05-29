// Adjacencies LIST

//sample input
// 6 1 2 1 3 2 4 2 5 3 5 4 5 4 6 5 6 0 0 3 1
// nodes ... Source Destination Source Destination Source Destination ... start node
// 0 0 to stop Entering Source Destination

#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};

void insert(struct node * a[],int i, int j)
{   
 // insert node at the front of the list
    struct node *temp;
    temp=(struct node *)(malloc(sizeof(struct node)));
    temp->data = j;
    temp->next= a[i];
    
    a[i]=temp;
}

void creategraph(struct node * a[],int n)
{
 int i,j;

  for(i=1;i<=n;i++)
	  a[i]=NULL;
  
  while(1)
  {
  printf("Enter the source and destination");
  scanf("%d %d",&i,&j);
	
  if((i==0)&&(j==0))break;
  	insert(a,i,j);
      insert(a,j,i);
    }
}


void al_dfs(struct node *a[],int * visted,int n,int v)
{
    visted[v]=1;
    printf("%d -> ",v);
    struct node * temp = a[v];
    while (temp!=NULL)
    {
        if (visted[temp->data]==0)
        {
            al_dfs(a,visted,n,temp->data);
        }
        temp=temp->next;
        
    }
    

}




int main()
{
    printf("ENTER THE NUMBER OF NODES\n");
    int n;
    scanf("%d",&n);
    struct node *a[n+1];
    creategraph(a,n);
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        struct node *temp=a[i];
        printf("a[%d] -> ",i);
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
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
	printf("The graph traversed using DFS is ");
    al_dfs(a,visted,n,v);
    

}