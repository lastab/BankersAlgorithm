#include<stdio.h>
#define process 3 //total number of process
#define resource 3 //total types of different resources

////Variables
int flagComplete[process]={0,0,0};//flag to check if the all the process has finished its tasks or not
int e[resource];//matrix to store total resource that the system has
int a[resource];//matrix to store total available or unused resource
int c[resource][process];//matrix to store data of each roesurce taken by each process
int r[resource][process];//matrix to store data of each resource that a process requires 

////functions

void readMatrix();//read content of matrices e,c,r
void status();//displays contents of all matrices e,a,c,r
void getA();//generate available resources
int runableProcess();//returns the runable process number(-1 if no runable process is found)
void runProcess(int);//runs the given process and frees the resources used by the process so that it is available to run other processes


int main()
{
	int result;
	readMatrix();
	getA();
	for (int x=0;x<process;x++)
	{	
		status();
		result = runableProcess();
		if(result==-1)
		{	
			{
				printf("\nNON OF THE PROCESS CAN RUN \n The process is Deadlock");
				return 1;
			}
		}
		else 
		{
			printf("\n PROCESS %d CAN RUN",result);			
			runProcess(result);
			flagComplete[result]=1;
		}
	}
	printf("\nAll of the process has been processed");
	status();
	return 0;
}

void getA()
{
	int temp[resource]={0,0,0};
	for (int i=0 ; i<process;i++)
		{for (int j=0;j<resource;j++)
			temp[i]=temp[i]+c[j][i];
		}	
	for (int i=0;i<resource;i++)
	{
		a[i]=e[i]-temp[i];		
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

