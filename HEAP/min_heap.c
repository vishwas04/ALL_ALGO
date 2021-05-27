#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int count=0;


void add(int * q,int d)
{
    if(count==MAX)
    {
        printf("Queue is full");
        return;
    }

    int x;
    x=d;
    q[count]=x;
    count++;
    int i=count-1;
    int j=(i-1)/2;
    while (i>0 && q[j] > x)
    {
        q[i]=q[j];
        i=j;
        j=(i-1)/2;
    }
    q[i]=x;
    
}
void getmin(int * q)
{
    if(count==0)
    {
        printf("EMPTY\n");
        return;
    }
    printf("Smallest -> %d\n",q[0]);
}


void adjust(int * q)
{ 
     int i,j=0;
     int key;

     key=q[0];
     i=1;
      
     while(i<=count-1)
     {
      if((i+1)<=count-1)
      {
        if(q[i+1]<q[i])
           i++;//get the index of the smallest child
      }
       if(key > q[i])
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



void delete(int * q)
{
    if(count==0)
    {
        printf("EMPTY\n");
        return;
    }
    int temp;
    temp=q[0];
    printf("%d Deleted\n",temp);
    q[0]=q[count-1];
    (count)--;
    adjust(q);
}

int main()
{
    int q[MAX];
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
            int d;
            scanf("%d",&d);
            add(q,d);
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
                printf("%d ",q[i]);
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