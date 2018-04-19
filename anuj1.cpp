#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int k,j,q,i,n,ts,temp,si,pos;
int aw;                      
float awt,totalt=0.0;
int qname[MAX],bt[MAX],wt[MAX],te[MAX],rt[MAX],at[MAX],tr[MAX];
int n1=0; 
void input()
{
	printf("Enter total no of Process:");
    scanf("%d",&n);
    n1=n;
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
    		printf("\nProcess p%d has been discarded because it's arrival time is %d",qname[i],at[i]);
    		for(j=pos;j<n-1;j++)
    		{
    			at[j]=at[j+1];
    			qname[j]=qname[j+1];
    			bt[j]=bt[j+1];
			}
			n1--;
		}
	}
   ts=2;
	q=ts;
}
void calculation()
{
    printf("\n -----------process ------------------ \n");
    j=0;
    printf("\nGant chart\n");
    printf("\nProcess\tRunning time\n");
    while(j<=n1)
    {
        j++;
        for(i=0;i<n1;i++)
        {
            if(rt[i]==0)  continue;
            if(rt[i]>ts)
           {
           		rt[i]=rt[i]-ts;
                printf("p%d\t\t%d\n",qname[i],q);
                q=q+ts;
                te[i]=te[i]+1;
            }
            else
            {
                wt[i]=q-te[i]*ts;
                q=q+rt[i]; 
                rt[i]=rt[i]-rt[i];
                tr[i]=wt[i]+rt[i];
                printf("p%d\t\t%d\n",qname[i],q);
            }
        }
    }
    float totaltr=0;
	printf("\nprocess\tWaiting Time\tTurnarround Time");
	for(int i=0;i<n1;i++)
	{
		tr[i]=wt[i]+bt[i];
		totaltr+=tr[i];
		printf("\np%d\t\t%d\t\t%d",qname[i],wt[i],tr[i]);
	}   
	printf("\nAverage waiting time=%.2f",totalt/n1);   
	printf("\nAverage turnarround time=%.2f",totaltr/n1);                                 
}
int main()
{
	input();
	calculation();
}
