#include<stdio.h>
struct process
{
	int processID, burstTime, arrivalTime, priority, waitTime;
};
int total_time,burst_time=0, total=-1,i=-1; 
struct process queue[100],result[100],swap;
int proces()
{
	int p;
	printf("Number of Processes =");
	scanf("%d",&p);
	return p;
}
void execute()
{
	if(total>=0)
	{
		int wait,j;
		if(burst_time!=0 && queue[0].burstTime!=0)
		{
			queue[0].burstTime--;
			burst_time--;
			queue[0].priority++;
			queue[0].arrivalTime=total_time+1;
			total_time++;	
			for(wait=1;wait<=total;wait++)
			{
				queue[wait].priority+=2;
				queue[wait].waitTime=++queue[wait].waitTime;
			}
		}
		if(queue[0].burstTime==0)
		{
			i++;
			result[i]=queue[0];
			for(wait=0;wait<total;wait++)
			{
				queue[wait]=queue[wait+1];
			}
			total--;
		}
		for(wait=0;wait<total;wait++)
		{
			for(j=0;j<total;j++)
			{
				if(queue[wait].priority<=queue[j].priority)
				{
					swap=queue[wait];
					queue[wait]=queue[j];
					queue[j]=swap;
				}
			}
		}
		if(queue[0].priority<=queue[1].priority && total>=1)
		{
			swap=queue[0];
			for(wait=0;wait<total;wait++)
			{
				queue[wait]=queue[wait+1];
			}
			queue[total]=swap;
		}
	}
}
int main()
{
	int l,j,p=proces(),count=0;
	float averageWaitTime=0;
	struct process pcreate[p];
	for(l=0;l<p;l++)
	{
		pcreate[l].processID=l+1;
		printf("\nEnter Arrival time of P[%d]= ",l+1);
		scanf("%d",&pcreate[l].arrivalTime);
		printf("\nEnter Burst   time of P[%d]= ",l+1);
		scanf("%d",&pcreate[l].burstTime);
		pcreate[l].priority=0;
		pcreate[l].waitTime=0;
		burst_time=burst_time+pcreate[l].burstTime;
	}
	for(l=0;l<p;l++)
	{
		for(j=0;j<p;j++)
		{
		if(pcreate[l].arrivalTime<pcreate[j].arrivalTime)
		{
			swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=swap;
		}
		if(pcreate[l].arrivalTime==pcreate[j].arrivalTime)
		{
			if(pcreate[l].burstTime<=pcreate[j].burstTime)
			{
			swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=swap;
			}
	 	}
	    }
}//
	printf("\n\nData entered by User As Per the Arrival Time\n\n");
	printf("					*Process Table* \n");
	printf("Process ID           Arrival Time        Service Time \n");
	for(l=0;l<p;l++)
	{
		printf(" %d            	   %d                   %d\n",pcreate[l].processID,pcreate[l].arrivalTime,pcreate[l].burstTime );
	}
	total_time=pcreate[0].arrivalTime;
	for(j=pcreate[0].arrivalTime;j<=pcreate[p-1].arrivalTime;j++)
	{
		for(l=0;l<p;l++)
		{
			if(pcreate[l].arrivalTime==j && count!=p)
			{
				total++;
				queue[total]=pcreate[l];
				count++;
			}
			if(count==p)
				break;
		}
		execute();
		total_time++;
	while(burst_time!=0 && count==p)
	{
		execute();
		total_time++;
	}
	if(count==p)
		break;
	}
	printf("\n\nProcess As Per Their Complelion\n\n");
	printf("					**Final Execution Table** \n");
	printf("Process ID           Arrival Time        Service Time          Waiting Time\n");
	for(l=0;l<p;l++)
	{
		for(j=0;j<p;j++)
		{
			if(result[l].processID==pcreate[j].processID)
			{
	printf("  	%d                  %d                    %d                    	%d\n",result[l].processID,pcreate[j].arrivalTime,pcreate[j].burstTime,result[l].waitTime);
			break;
			}
		}
		averageWaitTime+=(result[l].waitTime);
	}
	printf("Average Waiting Time =%f\n",averageWaitTime/p);
}	
