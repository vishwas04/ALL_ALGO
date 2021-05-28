#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

void good_suffix_table(int * good,int m,char *p)
{
    good[0]=m;
    for (int i = m-1; i >=1; i--)
    {
        char q[m-i+1];
        int o=0;
        for (int j = i; j < m; j++)
        {
            q[o]=p[j];
            o++;
        }
        for (int x = m-2; x >= (strlen(q)-1); x--)
        {
            int y= x-strlen(q)+1;
            
            int z=0;
            while (z<strlen(q) && p[y+z]==q[z])
            {
                z++;
            }
            if (z==strlen(q))
            {
                if (y-1 >= 0)
                {
                    if (p[y-1]!=p[i-1])
                    {
                        if (m-i-1==0)
                        {
                            int r=m-strlen(q)-y;
                        }
                        
                        good[m-i-1]=m-strlen(q)-y;
                        break;
                    }
                    
                }
                else
                {
                        if (m-i-1==0)
                        {
                            int r=m-strlen(q)-y;
                        }
                        good[m-i-1]=m-strlen(q)-y;
                        break;
                }
                
            }
            if (x<0)
            {
                break;
            }
            
            
        }
        
        
    }
    for (int i = 0; i < m-1; i++)
    {
        if(good[i]==-1)
        {
            good[i]=good[i-1];
        }
    }
    
    
}

int boyer_moore_found(char * t,char * p)
{
    int n=strlen(t);
    int m=strlen(p);
    if(m>n)
        printf("\nWARNING pattern is larger that text\n");
    int good[m-1];
    for (int i = 0; i < m-1; i++)
    {
        good[i]=-1;
    }
    
    good_suffix_table(good,m,p);
    printf("good_suffix_table\n");
    for (int i = 0; i < m-1; i++)
    {
        printf("%d ",good[i]);
    }


    int bad[256];
    for (int i = 0; i < 256; i++)
    {
        bad[i]=m;
    }
    int i=0;
    while(p[i]!='\0' && i!=m-1)
    {
        bad[p[i]]=m-i-1;
        i++;
    }
    
    i = m-1;
    while (i < n)
    {
        int k=0;
        // printf("%c%c ",p[m-k-1],t[i-k]);
        while (k<m && p[m-k-1]==t[i-k])
        {
            k++;
        }
        if(k==m)
            return 1;
        // printf("%d %d %d\n",k,max(bad[t[i-k]]-k,1),good[k-1]);
        if (k==0)
        {
            i=i+bad[t[i-k]];
        }
        else
            i=i+max(max(bad[t[i-k]]-k,1),good[k-1])-1;

    }
    return 0;
    
}


int main()
{
    int m;
    int n;

    printf("LENGTH OF TEXT ?\n");
    scanf("%d",&n);
    char * t =malloc((sizeof(char)* n)+1);
    printf("ENTER TEXT\n");
    scanf("%s",t);

    printf("LENGTH OF PATTERN ?\n");
    scanf("%d",&m);
    char * p =malloc((sizeof(char)* m)+1);
    printf("ENTER PATTERN\n");
    scanf("%s",p);

    if(boyer_moore_found(t,p))
        printf("\nFOUND\n");
    else
        printf("\nNOT FOUND\n");
    
    free(t);
    free(p);
    t=NULL;
    p=NULL;


}