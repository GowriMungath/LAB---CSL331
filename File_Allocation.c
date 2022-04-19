#include<stdio.h>
#include<stdlib.h>
int ch,f[200],i,st,len,p,ind[50],n,a,k,c;
void sequential(int f[])
{
    int flag=0;
    printf("Enter starting block and length of file: ");
    scanf("%d%d",&st,&len);
    for(i=st;i<(st+len);i++)
    {
        if(f[i]==0)
        {
            flag++;
        }
    }
    if(flag==len)
    {
        for(i=st;i<(st+len);i++)
        {
            f[i]=1;
            printf("%d->%d\n",i,f[i]);
        }
        if(i!=(st+len-1))
        {
            printf("File has been allocated\n");
        }
    }
    else
    {
        printf("File not allocated as block is already occupied!\n");
    }
}
void indexed(int f[])
{
    X:
    printf("Enter Index Block: ");
    scanf("%d",&p);
    if(f[p]==1)
    {
        printf("Block already allocated!\n");
        goto X;
    }
    else
    {
        printf("Enter number of files: ");
        scanf("%d",&n);
        printf("Enter files: ");
        for(i=0;i<n;i++)
        {
            scanf("%d",&ind[i]);
        }
        for(i=0;i<n;i++)
        {
            if(f[ind[i]]==1)
            {
                printf("Block already allocated!\n");
                goto X;
            }
        }
        for(i=0;i<n;i++)
        {
            f[ind[i]]=1;
            printf("%d->%d:%d\n",p,ind[i],f[ind[i]]);
        }
    }
}
void linked(int f[])
{
    printf("Enter number of blocks that are already allocated: ");
    scanf("%d",&n);
    printf("Enter blocks: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        f[a]=1;
    }
    printf("Enter starting block and length of file: ");
    scanf("%d%d",&st,&len);
    k=len;
    for(i=st;i<(st+k);i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            printf("%d->%d\n",i,f[i]);
        }
        else
        {
            printf("Block already allocated!\n");
            k++;
        }
    }
}
int main()
{
    for(i=0;i<200;i++)
    {
        f[i]=0;
    }
    c=1;
    while(c==1)
    {
        printf("Sequential File Allocation\nIndexed File Allocation\nLinked File Allocation\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            sequential(f);
            break;
            case 2:
            indexed(f);
            break;
            case 3:
            linked(f);
            break;
            default:
            exit(0);
        }
        printf("Continue? Yes-1/No-0: ");
        scanf("%d",&c);
    }
}
