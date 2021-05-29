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


void al_bfs(struct node *a[],int * visted,int n,int v,int * q)
{
    qinsert(v,q);
    visted[v]=1;
    while (qisempty()!=1)
    {
        struct node * temp=a[v];
        v=qdelete(q);
        printf("%d ->",v);
        while (temp!=NULL)
        {
            if (visted[temp->data]==0)
            {
                qinsert(temp->data,q);
                visted[temp->data]=1;
            }
            temp=temp->next;
            
        }
        
        
    }
    
    

}

//sample input
// 3 1 2 1 3 2 3 0 0

//6 1 2 1 3 2 4 2 5 3 5 4 5 4 6 5 6 0 0 1

int main()
{
    printf("ENTER THE NUMBER OF NODES\n");
    int n;
    scanf("%d",&n);
    struct node * a[n+1];
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
	printf("The graph traversed using BFS is ");
    int q[n+1];
    al_bfs(a,visted,n,v,q);
    

}