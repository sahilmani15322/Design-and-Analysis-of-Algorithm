#include<stdio.h>
#include<stdlib.h>
int place(int r2,int c2,int x[])
{
	int r1,c1;
	for(r1=0;r1<r2;r1++)
	{
		c1=x[r1];
		if(x[r1]==c2 || abs(r1-r2)==abs(c1-c2))
			return 0;
	}
	return 1;
}

void recSolution(int k,int n,int x[],int no_of_sol)
{
	int c,i,j;
	static int possible=0,index=0;
	
	for(c=0;c<n;c++)
	{
		if(place(k,c,x))
		{
			
			x[k]=c;
			if(k==n-1)
			{ 
				printf("The Solution %d is:\n",++index);
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if(j==x[i])
							printf("Q  ");
						else
							printf(".  ");
					}
					printf("\n");
				}
				if(no_of_sol==1)
				{
					possible=1;return;
				}	
			}
			else
			{
				recSolution(k+1,n,x,no_of_sol);
			}
		}
		if(possible==1)
		{
			return;
		}
	}
	
}
void itrSolution(int n,int sol)
{
	int k=0,i,j,index=1;
	
	int *x;
	x=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		x[i]=-1;
	}
	while(k!=-1)
	{
		x[k]++;
		if(x[k]<n)
		{
			if(place(k,x[k],x))
			{
				if(k==n-1)
				{
					printf("The Solution no. %d is:\n",index++);
					for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
						{
							if(j==x[i])
								printf("Q  ");
							else
								printf(".  ");
						}
						printf("\n");
					}
					if(sol==1)
						return ;
				}
				else
					k++;
			}
		}
		else
		{
			x[k]=-1;
			k--;
		}
	}
	free(x);
}
int main()
{
	int i,j,s,n;
	int * x;
	
	do
	{
	
	printf("\nN-QUEEN PROBLEM");
	printf("\n1.Iterative Algorithm");
	printf("\n2.Recursive Algorithm");
	printf("\n3.Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&s);
	switch(s)
	{
		int s1;
		case 1:
			do{
				printf("\nUsing Iterative Version:\n");
				printf("\n1.Print all solutions?");
				printf("\n2.Print only one solution?");
				printf("\n3.Return");
				printf("\nEnter your choice: ");
				scanf("%d",&s1);
				switch(s1)
				{
					case 1:
						printf("\nEnter the no. of queens: ");
						scanf("%d",&n);
						if(n<4)
						{
							printf("The solution is not possible for queens less than 4!!!");
						}
						else
						{
							itrSolution(n,0);
							//char arr[n][n];
							
						}
					break;
					case 2:
						printf("\nEnter the no. of queens: ");
						scanf("%d",&n);
						if(n<4)
						{
							printf("The solution is not possible for queens less than 4!!!");
						}
						else
						{
							itrSolution(n,1);
							
						}
					break;
				}
			}while(s1!=3);
			break;
		case 2:
			do{
		
			
			printf("\nUsing Recusive Version:\n");
			printf("\n1.Print all solutions?");
			printf("\n2.Print only one solution?");
			printf("\n3.Return");
			printf("\nEnter your choice: ");
			scanf("%d",&s1);
			switch(s1)
			{
				case 1:
					
					printf("\nEnter the no. of queens: ");
					scanf("%d",&n);
					//x=(int*)malloc(n*sizeof(int));
					if(n<4)
					{
						printf("The solution is not possible for queens less than 4");
					}
					else
					{
						x=(int*)malloc(n*sizeof(int));
						recSolution(0,n,x,0);
						free(x);
					}
					
				break;
				case 2:
					
					printf("\nEnter the no. of queens: ");
					scanf("%d",&n);
		     		if(n<4)
					{
						printf("The solution is not possible for queens less than 4");
					}
					else
					{
						x=(int*)malloc(n*sizeof(int));
						recSolution(0,n,x,1);
						free(x);
						
					}
				break;
			}
			}while(s1!=3);
		break;
		case 3:
			printf("Thankyou!!");
		break;
	}
	
	}while(s!=3);
}
