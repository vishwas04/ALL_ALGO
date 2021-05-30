#include<stdio.h>
#include<stdlib.h>
# define MAX 10

struct node
{
    int data;
    int priority;
}Node;

int count=0;
void add(struct node * q,int d,int p)
{
    if(count==MAX)
    {
        printf("Queue is full");
        return;
    }

    struct node x;
    x.data=d;
    x.priority=p;
    q[count]=x;
    count++;
    int i=count-1;
    int j=(i-1)/2;
    while (i>0 && q[j].priority > x.priority)
    {
        q[i]=q[j];
        i=j;
        j=(i-1)/2;
    }
    q[i]=x;
    
}



void adjust(struct node * q)
{ 
     int i,j=0;
     struct node key;

     key=q[0];
     i=1;
      
     while(i<=count-1)
     {
      if((i+1)<=count-1)
      {
        if(q[i+1].priority<q[i].priority)
           i++;//get the index of the smallest child
      }
       if(key.priority > q[i].priority)
       {
            q[j]=q[i]; //move the child up
            j=i;
            i=2*j+1;
       }
       else
          break;
      }
      q[j]=key; 
}



struct node delete(struct node * q)
{   
    struct node temp;
    if(count==0)
    {
        printf("EMPTY\n");
        return temp;
    }
    
    temp=q[0];
    //printf("%d %d Deleted",temp.data,temp.priority);
    q[0]=q[count-1];
    (count)--;
    adjust(q);
    return temp;
}
int find(struct node q[],int selected)
{
    for (int i = 0; i < count; i++)
    {
        if (q[i].data==selected)
        {
            return q[i].priority;
        }
        
    }
    printf("error");
    return -1;
}
void update(struct node q[],int v,struct node selected,int n,int a[][n+1])
{
    for (int i = 0; i < count; i++)
    {
        if (q[i].data==v)
        {
            q[i].priority=a[selected.data][i]+selected.priority;
        }
                    
    }
}
//6 1 2 3 1 6 5 1 5 6 2 6 4 2 3 1 3 4 6 3 6 4 4 6 5 4 5 8 5 6 2 0 0 0
void relaxation(struct node q[],int n,int a[][n+1],struct node selected,int * vis)
{
    for (int i = 1; i <=n ; i++)
    {
        if (a[selected.data][i] && vis[i]==0)
        {
            if (selected.priority+a[selected.data][i] < find(q,i) )
            {
                //output[i]=output[selected]+a[selected][i];
                //update(q,i,selected,n,a);
                for (int o = 0; o < count; o++)
                {
                    if (q[o].data==i)
                    {
                        q[o].priority=a[selected.data][i]+selected.priority;
                    }
                                
                }
            }
            
        }
    }
}




void dijkstra(int n,int a[][n+1],int v)
{
    struct node q[MAX];
    add(q,v,0);

    for (int i = 1; i <= n; i++)
    {
        
        if (a[v][i]==0 && v!=i)
        {
            add(q,i,99999999);
        }
        else if (a[v][i] && v!=i)
        {
            add(q,i,a[v][i]);
        }
    }
    
    int vis[n+1];
    for (int i = 1; i <= n; i++)
    {
        vis[i]=0;
    }
    vis[v]=1;
    while (count!=0)
    {
        struct node temp=delete(q);
        printf("from %d to %d Minimum Distance is %d\n",v,temp.data,temp.priority);
        vis[temp.data]=1;
        relaxation(q,n,a,temp,vis);
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
        a[j][i]=w;
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
    
    //printf("\nmin span tree-\n");
    int v;
    printf("Enter the source vertex");
    scanf("%d",&v);
    dijkstra(n,a,v);
}