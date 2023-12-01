#include <stdio.h>

int BinarySearch(int *data,int size , int key);

int main(void)
{

  int arr[5]={7,9,1,5,3};

 int res; 

 res=BinarySearch(arr,5,1);      
 
 
 if(res==-1)
      printf("The Element Not Exist");
 else
    printf("The Element is Found in Index %d\n",res);

} 



int BinarySearch(int *data ,int size, int key)
{
   int mid, l=0,h=size-1;

   while(l<h)
   {
      mid=(l+h)/2;

      if(data[mid] < key)
	{
          l=mid+1 ;
        }

	else if(data[mid]>key)
	{
          h=mid-1;
        }
	else
	   return mid;
	}
   return -1;
}
