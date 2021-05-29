#include<stdio.h>
#include<stdlib.h>
void disp(int * x,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",x[i]+1);
    }
    printf("\n"); 
}

int find_moblie(int *x,int *d,int n)
{
    int max;
    max =-1;
    for (int i = n-1; i >=0; i--)
    {
        if(i!=0)
        {
            if(d[x[i]] == 0 && x[i] > x[i-1] && max < x[i])//if x[i] has direction left
            {
                max=x[i];
            }
        }

        if(i != n-1)
        {
            if(d[x[i]] == 1 && x[i] > x[i+1] && max < x[i])//if x[i] has direction right
            {                
                max=x[i];
            }
        }
    }
    return max;
}





void johnson_trotter (int n)
{
    if (n < 0)
    {
        printf("vade enter Positive number\n");
        return;
    }
    
    int x[n];//Present Permutation 
    int d[n];//direction
    for (int i = 0; i < n; i++)
    {
        x[i]=i;
        d[i]=0;
    }
    int y = find_moblie(x,d,n);
    int t;
    disp(x,n);
    while(y!=-1)
    {
        for (int i = 0; i < n; i++)//find and swap
        {
            if(x[i]==y)//find that mobile element
            {
                if(d[y]) //if direction is right
                {
                    t=x[i];
                    x[i]=x[i+1];
                    x[i+1]=t;
                    break;
                }
                else     //if direction is left
                {
                    t=x[i];
                    x[i]=x[i-1];
                    x[i-1]=t;
                    break;
                }
            }
        }
        for (int j = 0;j < n; j++)//change the direction of all greater that moblie element
        {
            if(j > y)
            {
                if(d[j])
                {
                    d[j]=0;
                }
                else
                {
                    d[j]=1;
                }
            }
        }

        disp(x,n);
        y=find_moblie(x,d,n);
    }
}


int main()
{
    printf("n -> ");
    int n;
    scanf("%d",&n);
    johnson_trotter(n);
}