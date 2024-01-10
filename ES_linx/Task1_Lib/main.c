#include <stdio.h>
#include "operation.h"

int main()
{
  int ad ,sb,ml,dv,x,y;

  printf("Enter the Num1:");
  scanf("%d",&x);
  
  printf("Enter the Num2:");
  scanf("%d",&y);

 ad=add(x,y);
 sb=sub(x,y);
 ml=mul(x,y);
 dv=div(x,y);
 printf("The Addition : %d \n ",ad);
 return 0;
}
