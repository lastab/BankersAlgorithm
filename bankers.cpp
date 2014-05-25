#include<stdio.h>
#include <math.h>
#define process 3
#define resource 3
int e[resource];
int a[resource];
int c[resource][process];
int r[resource][process];
int temp[resource];
void generateA();
void readMatrix();
void status();
void getA();
int runableProcess();

int main()
{
	readMatrix();
	getA();
	status();
	if(runableProcess()==-1)
	{
			printf("\nNON OF THE PROCESS CAN RUN \n The process is Deadlock");
	}
	else 
	{
			printf("\n PROCESS %d CAN RUN",runableProcess());
	}
	return 0;
}

void getA()
{
	temp[0]=0;
	temp[1]=0;
	temp[2]=0;	
	for (int i=0 ; i<process;i++)
		{for (int j=0;j<resource;j++)
			temp[i]=temp[i]+c[j][i];
		printf("%d    ,  ",temp[i]);
		}	
	for (int i=0;i<resource;i++)
	{
		a[i]=e[i]-temp[i];
		printf("%d-%d=%d   ",e[i],temp[i],a[i]);
	}
			
}

void status()
{
	int i,j;
		printf("\n\n \nE\n");
		for (i=0;i<resource ;i++)
		{
			printf("%d, ",e[i]);
		}
		printf("\n \nR\n");
		for (i=0;i<process ;i++)
		{
			for (j=0;j<resource;j++)
			{	
				printf(" %d,",r[i][j]);
			}
			printf("\n");
		}
		
		printf("\n  C\n");
		for (i=0;i<process ;i++)
		{
			for (j=0;j<resource;j++)
			{	
				printf(" %d ",c[i][j]);
			}
			printf("\n");
		}
		printf(" A\n");
		for (i=0;i<resource ;i++)
		{
			printf("%d,",a[i]);
		}
		
}


void readMatrix()
{
	int i,j;
		printf("enter E\n");
		for (i=0;i<resource ;i++)
		{
			printf("e[%d]",i);
			scanf("%d",&e[i]);
		}
	printf("\n enter R\n");
		for (i=0;i<process ;i++)
		{
			printf("for process %d",i);
			for (j=0;j<resource;j++)
			{					
				scanf("%d",&r[i][j]);
			}
		}
		
		printf("\n enter C\n");
		for (i=0;i<process ;i++)
		{
			printf("for process %d",i);
			for (j=0;j<resource;j++)
			{					
				scanf("%d",&c[i][j]);
			}
		}
		
}

int runableProcess()
{
	int possible;
	for (int j=0;j<resource;j++)
		{
		possible=0;
		for (int i=0;i<process;i++)
			{
				if (a[i]-r[j][i]>=0)
				{	
					possible++;
				}
			}
		if (possible==3)
				return j;
		}
		return -1;
	
}
