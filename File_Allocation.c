#include<stdio.h>
#include<stdlib.h>
int f[200],ch,i,j,ind[50],p,n,a,st,len,k;
void sequential(int f[])
{
    int count = 0;
    printf("Enter the starting block and the length of the file: ");
    scanf("%d%d", &st, &len);
    for (i=st; i<(st+len); i++)
    {
        if (f[i] == 0)
        {
            count++;
        }
    }
    if(len == count)
    {
        for (int j=st; j<(st+len); j++)
        {
            if (f[j] == 0)
            {
                f[j] = 1;
                printf("%d->%d\n",j,f[j]);
            }
        }
        if (j != (st+len-1))
            printf("The file is allocated to the disk\n");
    }
    else
    {
        printf("The file is not allocated to the disk as some blocks are already allocated!\n");
    }
}
void indexed(int f[])
{
    int ind[i],n;
    X:
    printf("Enter the index block: ");
    scanf("%d",&p);
    if(f[p]==1)
    {
        printf("Block already allocated\n!");
        goto X;
    }
    else
    {
        f[p]=1;
        printf("Enter number of files on index: ");
        scanf("%d",&n);
        printf("Enter file blocks: ");
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
        }
        for(i=0;i<n;i++)
        {
            printf("%d->%d:%d\n",p,ind[i],f[ind[i]]);
        }
    }
}
void linked(int f[])
{
    printf("How many blocks are already allocated? ");
    scanf("%d",&n);
    printf("Enter the blocks: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        f[a]=1;
    }
    printf("Enter the starting block and the length of the file: ");
    scanf("%d%d", &st, &len);
    k=len;
    for(i=st;i<(st+k);i++)
    {
        if(f[i]==1)
        {
            printf("File block already allocated!\n");
            k++;
        }
        else
        {
            f[i] = 1;
            printf("%d->%d\n",i,f[i]);
        }
    }
}
int main()
{
    for(i=0;i<200;i++)
    {
        f[i]=0;
    }
    int c=1;
    while(c==1)
    {
        printf("\n1.Sequential File Allocation\n2.Indexed File Allocation\n3.Linked File Allocation\nEnter your choice: ");
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
    }
}
