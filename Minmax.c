#include<stdio.h>

void maxmin(int arr[],int i,int j,int *max,int *min)
{
	 int maxt,mint,mid;
	 
	 if(i==j)	
	  *max=*min=arr[i];
	 else
	 {
	  if(i==j-1)  
	  {
		   if(arr[i]<arr[j])
		   {
			    *max=arr[j];
			    *min=arr[i];
		   }
		   else
		   {
			    *max=arr[i];
			    *min=arr[j];
		   }
	  }
	  else
	  {
		   mid=(i+j)/2;
		   maxmin(arr,i,mid,max,min); 
		   maxt=*max;		
		   mint=*min;	
		   maxmin(arr,mid+1,j,max,min);
		   if(*max<maxt) 
		    *max=maxt;
		   if(*min>mint)
		    *min=mint; 
	  }
	 }
}
int main()
{
	int max,min;
	int i, num;
	printf ("\nEnter size of array :: ");
	scanf ("%d",&num);
	int *ptr;
	ptr=(int*)malloc(num*sizeof(int));
	printf ("Enter the numbers :: \n");
	for(i=0;i<num;i++)
	scanf("%d",ptr+i);
	
	max=ptr[0];
	min=ptr[0];
	maxmin(ptr,0,num-1,&max,&min);
	printf ("Minimum Element :: %d\n", min);
	printf ("Maximum Element :: %d\n", max);
	free(ptr);
	return 0;
}
