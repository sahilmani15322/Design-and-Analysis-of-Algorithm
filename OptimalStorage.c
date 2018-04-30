#include <stdio.h>
#define SIZE 30
typedef struct arr	
{
	int index,value;
}arr;

void mergeSort(struct arr arr[], int n)
{
	struct arr arr1[SIZE],arr2[SIZE];
	int n1, n2; 
    int i,j,k; 
    struct arr  temp;
         
    if(n % 2 == 0)
        n1 = n2 = n/2;
    else
    {
        n1 = n/2;
        n2 = n - n1;
    }
    
    for(i =0 ; i< n1; i++)
    {
        arr1[i]= arr[i];
	}
    for(i =0 ; i< n2; i++)
	{
        arr2[i]= arr[i+n1];
	}
    if(n1 == 2)
    {
        if(arr1[0].value > arr1[1].value)
        {
            temp = arr1[0];
            arr1[0] = arr1[1];
            arr1[1] = temp;
        }
    }
    else if(n1 > 2)
    {
        mergeSort(arr1, n1);
    }  
    if(n2 == 2)
    {
        if(arr2[0].value > arr2[1].value)
        {
            temp = arr2[0];
            arr2[0] = arr2[1];
            arr2[1] = temp;
        }
    }
    else if(n2 > 2)
    {
        mergeSort(arr2, n2);
    }
    i = j = k = 0;
    while(i < n1 && j < n2)
    {
        if(arr1[i].value <= arr2[j].value)
        {
            arr[k]= arr1[i];
            i++;
            k++;
        }
        else if(arr2[j].value < arr1[i].value)
        {
            arr[k]= arr2[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
      arr[k]= arr2[j];
        j++;
        k++;
    }
}

main()
{
	int a,i,n,sum1=0,sum=0;
	printf("Enter the number of jobs :");
	scanf("%d",&n);
	
	arr arr[n];		
	
	int *ar= (int *)malloc(n*sizeof(int));
	printf("\n\nEnter the time of each job : ");  
	for(i=0;i<n;i++)
	{
		scanf("%d",ar[i]);
		arr[i].value=*(ar+i);
		arr[i].index=i+1;
	}
	
    mergeSort(arr,n);			
    
    
    printf("\n\nS.No \t JOB NO \t TIME \t RETRIEVAL TIME");
	
    for(i=0;i<n;i++)
	{
		sum1=sum1+(arr[i].value);
		printf("\n%d \t  %d\t\t  %d \t  %d",i+1,arr[i].index,arr[i].value,sum1);
		sum+=sum1;
	}
    printf("\n\nTOTAL RETRIEVAL TIME : %d",sum);
    printf("\n\nOPTIMAL TIME : %f",(float)sum/n);  
    free(ar);
}
