#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//SAMPLE INPUT
//6 1 2 3 1 6 5 1 5 6 2 6 4 2 3 1 3 4 6 3 6 4 4 6 5 4 5 8 5 6 2 0 0 0
//7 1 2 28 2 3 16 2 7 14 3 4 12 4 7 18 4 5 22 5 7 24 5 6 25 6 1 10 0 0 0
typedef struct edge {
  int u, v, w;
} edge;




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
// CAN USE BETTER SORTING ALGO
void sort(edge elist[],int n) {
  int i, j;
  edge temp;

  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++)
    if (elist[j].w > elist[j + 1].w) 
    {
        temp = elist[j];
        elist[j] = elist[j + 1];
        elist[j + 1] = temp;
    }
}
void applyUnion(int belongs[], int c1, int c2,int n) {
  int i;

  for (i = 1; i <= n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

void kruskals(int * belongs,int n,int a[][n+1])
{ 
    edge elist[MAX];
    int n1=0;
    edge spanlist[n+1];
    int n2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) //DONT NEED FOR BOTH DIRECTION
        {
            if (a[i][j] != 0) 
            {
                elist[n1].u = i;
                elist[n1].v = j;
                elist[n1].w = a[i][j];
                n1++;
            }
        }
    }
    sort(elist,n);
    // for (int i = 0; i < n1; i++)
    // {
    //     printf("%d %d %d\n",elist[i].u,elist[i].v,elist[i].w);
    // }
    // printf("\n\n");
    for (int i = 1; i <=n; i++)
        belongs[i] = i;

    n2 = 0;

    for (int i = 0; i < n1; i++) {
        int cno1 = belongs[elist[i].u];
        int cno2 = belongs[elist[i].v];

        if (cno1 != cno2) 
        {
        printf("from %d to %d with path %d\n",elist[i].u,elist[i].v,elist[i].w);
        spanlist[n2] = elist[i];
        n2=n2 + 1;
        applyUnion(belongs, cno1, cno2,n);
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
    int belongs[n+1];
    for (int i = 0; i < n+1; i++)
    {
        belongs[i]=i;
    }
    printf("\nmin span tree-\n");
    kruskals(belongs,n,a);
}