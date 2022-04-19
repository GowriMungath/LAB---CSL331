#include<stdio.h>
#include<stdlib.h>
int ch,n,ino[20],quantum,i,j;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void findwaitingtime(int b[20],int tat[20],int wt[20])
{
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-b[i];
    }
}
void findturnaroundtime(int a[20],int b[20],int tat[20],int wt[20])
{
    if(ch==1||ch==2)
    {
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum+=b[i];
            tat[i]=sum-a[i];
        }
        findwaitingtime(b,tat,wt);
    }
    else if(ch==3)
    {
        int sum=0;
        int b_rem[20];
        int flag=1;
        for(i=0;i<n;i++)
        {
            b_rem[i]=b[i];
        }
        while(flag==1)
        {
            for(i=0;i<n;i++)
            {
                if(b_rem[i]>0)
                {
                    flag=1;
                    if(b_rem[i]>quantum)
                    {
                        sum+=quantum;
                        b_rem[i]-=quantum;
                    }
                    else
                    {
                        sum+=b_rem[i];
                        tat[i]=sum-a[i];
                        b_rem[i]=0;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                if(b_rem[i]!=0)
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        findwaitingtime(b,tat,wt);
    }
}
void display(int a[20],int b[20],int tat[20],int wt[20])
{
    printf("Process\tArrivalTime BurstTime waitingTime TurnAroundTime\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%d\t%d\t\t%d\n",ino[i],a[i],b[i],wt[i],tat[i]);
    }
}
void sort(int ino[20],int arrival[20],int a[20],int b[20])
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[i]<a[i+1])
            {
                a[i]=b[i];
            }
            else if(b[j]>b[j+1])
            {
                swap(&b[j],&b[j+1]);
                swap(&arrival[j],&arrival[j+1]);
                swap(&ino[j],&ino[j+1]);
            }
        }
    }
}
int main()
{
    int a[20],b[20],wt[20],tat[20],arrival[20];
    int c=1;
    while(c==1)
    {
        printf("1.FCFS\n2.SJF\n3.Round Robin\nEnter your choice: ");
        scanf("%d",&ch);
        printf("Enter the number of processes: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            ino[i]=i;
            printf("Enter arrival time of process %d: ",i);
            scanf("%d",&a[i]);
            printf("Enter burst time of process %d: ",i);
            scanf("%d",&b[i]);
        }
        switch(ch)
        {
            case 1:
            findturnaroundtime(a,b,tat,wt);
            display(a,b,tat,wt);
            break;
            case 2:
            for(i=0;i<n;i++)
            {
                arrival[i]=a[i];
            }
            sort(arrival,ino,a,b);
            findturnaroundtime(arrival,b,tat,wt);
            display(arrival,b,tat,wt);
            break;
            case 3:
            printf("Enter time quantum: ");
            scanf("%d",&quantum);
            findturnaroundtime(a,b,tat,wt);
            display(a,b,tat,wt);
            break;
            default:
            exit(0);
        }
        printf("continue? Yes-1/No-0: ");
        scanf("%d",&c);
    }
}
