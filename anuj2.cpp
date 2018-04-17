#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int k,j,q,i,n,ts,temp,si,pos;
int aw;                      
float awt,totalt=0.0;
int qname[MAX],bt[MAX],wt[MAX],te[MAX],rt[MAX],at[MAX];
int n1=0; 
void input()
{
	printf("Enter total no of Process:");
    scanf("%d",&n);
    n1+=n;
    for(i=0;i<n;i++)
	{
		qname[i]=i+1;
	}
	si=n;
    printf("\nEnter burst  time and arriavl time of Process\n");
    for(i=0;i<n;i++)
    {
        printf("p%d  burst time: ",i+1);
        scanf("%d",&bt[i]);
        printf("\nariavl time :  ");
        scanf("%d",&at[i]);
        te[i]=0;     
		wt[i]=0;
		printf("\n\n");
    }
    printf("\nProcess\t burst time\tArrival time\n");
	for(i=0;i<n;i++)
	{
		printf("\np%d\t\t%d\t\t%d",i+1,bt[i],at[i]);
		rt[i]=bt[i];
	}
    for(i=0;i<n;i++)
    {
    	totalt+=bt[i];
	}
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
            	temp=qname[i];
            	qname[i]=qname[j];
            	qname[j]=temp;
                temp=at[i];                                          //sorting according to arrival time
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
    	pos=i;
    	if(at[i]==0)
    	{
    		for(j=pos;j<n-1;j++)
    		{
    			at[j]=at[j+1];
    			qname[j]=qname[j+1];
    			bt[j]=bt[j+1];
			}
		}
	}
   ts=2;
	q=ts;
}
