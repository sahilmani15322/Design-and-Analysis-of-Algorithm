#include<bits/stdc++.h>
using namespace std;

typedef struct graph
{
  int s;
  int d;
  int w;
};

int checkvalidation(struct graph *arr,int size,int s,int d)
{
    for(int i=0;i<size;i++)
    {
    	
        if((arr[i].s==s) && (arr[i].d==d) )
        return 0;
    }
    return 1;
}

int checknegativecyle(struct graph *gr,int *arr,int t)
{
    int flag=0,temp;
    for(int i=0;i<t;i++)
        {
            temp=arr[gr[i].s-1]+gr[i].w;
                if(arr[gr[i].s-1]!=INT_MAX&&arr[gr[i].d-1]>temp)
                    {
                        arr[gr[i].d-1]=temp;
                        flag=1;
                    }
        }
    if(flag==1)
    {
        cout<<"Negative Cycle Exist"<<endl;
        return 1;
    }
    return 0;
}

int main()
{
    int n=0,s,t=0;
    do
    {
      cout<<"Enter the no of Vertices::";
      cin>>n;
      if(n<=3)
      {
      	cout<<"No. of Vertices should be greater than 3!!!"<<endl;
	  }
    }while(n<=3);
    
    int *arr=(int*)malloc((n)*sizeof(int));
    for(int i=0;i<n;i++)
    	arr[i]=INT_MAX;
    	
    do
    {
      cout<<"Enter the the no of Edges::"<<endl;
      cin>>t;
      if(t<n-1)
      {
      	cout<<"Wrong No. of Edges!!!"<<endl;
	  }
    } while(t<n-1);

    graph *gr = (graph*)malloc(t*sizeof(graph));
    cout<<"Enter Edge from source->distination =weight"<<endl;
    for(int i=0;i<t;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        if(s==d||s>n || d>n || s<1 || d<1)
        {
            cout<<"RE-ENTER THE Edge"<<endl<<endl;
            i--;
        }
        else
        {
	        if(checkvalidation(gr,i,s,d))
	        {
	            gr[i].s=s;
				gr[i].d=d;
				gr[i].w=w;
	        }
	        else
	        {
	            cout<<"RE-ENTER THE Edge"<<endl<<endl;
	            i--;
	        }
        }
    }
    s=-1;
    do
	{
	    cout<<"Enter the Source vertex::";
	    cin>>s;
	    if(s<1 || s >n)
	    {
	    	cout<<"Wrong Source Vertex!!!"<<endl;
		}
    }while(s<1 || s >n);
    arr[s-1]=0;
    int temp;
    int flag=0;
    for(int j=1;j<n;j++)
    {
        flag=0;
        for(int i=0;i<t;i++)
        {
            temp=arr[gr[i].s-1]+gr[i].w;
                if(arr[gr[i].s-1]!=INT_MAX&&arr[gr[i].d-1]>temp)
                    {
                        arr[gr[i].d-1]=temp;flag=1;
                    }
        }
        if(flag==0)
        break;
    }
    if(flag==1)
    {
    	if(checknegativecyle(gr,arr,t))
	    {free(arr);free(gr);
	        return 0;
	    }
	}
    
    cout<<"Final result"<<endl;
    cout<<"Source   Destination   Distance"<<endl;
    for(int i=0;i<n;i++)
    {
            if(i!=s-1)
			{
				if(arr[i]==INT_MAX)
					cout<<s<<"            "<<i+1<<"         "<<"NOT DEFINE"<<endl;					
				
				else
	            	cout<<s<<"            "<<i+1<<"         "<<arr[i]<<endl;
            }
    }
	free(arr);free(gr);
}
