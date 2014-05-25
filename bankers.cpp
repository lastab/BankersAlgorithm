#include<stdio.h>
#define process 3
#define resource 3
//flag to check if the all the process has finished its tasks or not
int flagComplete[process]={0,0,0};
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
void runProcess(int);

int main()
{
	int result;
	readMatrix();
	for (int x=0;x<process;x++)
	{
		getA();
		status();
		result = runableProcess();
		if(result==-1)
		{	//Think this is not required
			/*if (flagComplete[0]==1 && flagComplete[1]==1 && flagComplete[2]==1)
			{
				printf("\nAll of the process has been processed");
				return 0;
			}	
			else*/
			{
				printf("\nNON OF THE PROCESS CAN RUN \n The process is Deadlock");
				return 1;
			}
		}
		else 
		{
			printf("\n PROCESS %d CAN RUN",result);
			////
				runProcess(result);
			////
			flagComplete[result]=1;
		}
	}
	printf("\nAll of the process has been processed");
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
		printf("\n \nE\n");
		for (i=0;i<resource ;i++)
		{
			printf("%d, ",e[i]);
		}
		printf("\n R\n");
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
		if (possible==3 && flagComplete[j]==0)
				return j;
		}
		return -1;	
}

void runProcess(int x)
{
	for(int i=0;i<resource;i++)
	{
		r[x][i]=0;
		a[i]+=c[x][i];
		c[x][i]=0;
	}
}
