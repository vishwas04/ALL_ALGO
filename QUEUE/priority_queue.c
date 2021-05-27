#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int count=0;

struct node
{
    int data;
    int priority;
}Node;

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
void getmin(struct node * q)
{
    if(count==0)
    {
        printf("EMPTY\n");
        return;
    }
    printf("Smallest -> %d %d\n",q[0].data,q[0].priority);
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



void delete(struct node * q)
{
    if(count==0)
    {
        printf("EMPTY\n");
        return;
    }
    struct node temp;
    temp=q[0];
    printf("%d %d Deleted",temp.data,temp.priority);
    q[0]=q[count-1];
    (count)--;
    adjust(q);
}

int main()
{
    struct node q[MAX];
    // for (int i = 0; i < 10; i++)
    // {
    //     q[i].data=rand()/10000000;
    //     q[i].priority=rand()/1000000;
    // }
    printf("1->add\n2->getmin\n3->delete\n4->print\n5->exit\n");  
    int x;
    scanf("%d",&x);
    while(x!=5)
    {
        if(x==1)
        {
            int d,p;
            scanf("%d",&d);
            scanf("%d",&p);
            add(q,d,p);
        }
        else if(x==2)
        {
            getmin(q);
        }
        else if(x==3)
        {
            delete(q);
        }
        else if(x==4)
        {
            for (int i=0;i<count;i++)
            {
                printf("%d %d\n",q[i].data,q[i].priority);
            } 
        }
        else
        {
            printf("vade put correct input\n");
        }
        printf("1->add\n2->getmin\n3->delete\n4->print\n5->exit\n");  
        scanf("%d",&x);
        
    } 
    

}