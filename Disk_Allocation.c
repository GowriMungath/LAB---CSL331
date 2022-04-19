#include<stdio.h>
#include<stdlib.h>
int ch,c,n,i,d,req[100],move,h,j,temp,difference,p;
void sort(int req[])
{
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1-i;j++)
        {
            if(req[j]>req[j+1])
            {
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
}
void fcfs()
{
    int seektime=0;
    for(i=0;i<n;i++)
    {
        difference=abs(req[i+1]-req[i]);
        seektime+=difference;
    }
    printf("Total head movements: %d\n",seektime);
}
void scan()
{
    int seektime=0;
    printf("Enter total disk size: ");
    scanf("%d",&d);
    d=d-1;
    printf("Choose direction: High-1/Low-0? ");
    scanf("%d",&move);
    req[0]=h;
    sort(req);
    for(i=0;i<=n;i++)
    {
        if(req[i]==h)
        {
            p=i;
            break;
        }
    }
    if(move==1)
    {
        difference=abs(d-req[p]);
        seektime+=difference;
        difference=abs(d-req[0]);
        seektime+=difference;
    }
    else
    {
        difference=abs(req[p]-0);
        seektime+=difference;
        difference=abs(req[n]-0);
        seektime+=difference;
    }
    printf("Total head movements: %d\n",seektime);
}
void cscan()
{
    int seektime=0;
    printf("Enter total disk size: ");
    scanf("%d",&d);
    d=d-1;
    req[0]=h;
    sort(req);
    for(i=0;i<=n;i++)
    {
        if(req[i]==h)
        {
            p=i;
            break;
        }
    }
    seektime+=abs(req[p]-d);
    seektime+=abs(d-0);
    seektime+=abs(0-req[p-1]);    
    printf("Total head movements: %d\n",seektime);
}
int main()
{
    c=1;
    while(c==1)
    {
        printf("1.FCFS\n2.SCAN\n3.C-SCAN\nEnter your choice: ");
        scanf("%d",&ch);
        printf("Enter number of requests: ");
        scanf("%d",&n);
        printf("Enter request sequence: ");
        for(i=1;i<=n;i++)
        {
            scanf("%d",&req[i]);
        }
        printf("Enter initial head position: ");
        scanf("%d",&h);
        req[0]=h;
        switch(ch)
        {
            case 1:
            fcfs();
            break;
            case 2:
            scan();
            break;
            case 3:
            cscan();
            break;
            default:
            exit(0);
        }
        printf("Continue? Yes-1/No-0: ");
        scanf("%d",&c);
    }
}
