#include<stdio.h>
int main()
{
	int a[10],n;
	printf("nhap vao so phan tu ");
    scanf("%d",&n );
   for( int i=0;i<n;i++)
   {
   	printf("nhap vao so phan tu trong mang a[%d]: ",i);
   	scanf("%d",& a[i] );
   }
  printf("so phan tu da nhap la \n");
  for (int i=0;i<n;i++)
   {printf("a[%d]=%d \n",i,a[i]);
   }
   
   int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
               
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    
    
    printf("\nMang da sap xep la: ");
    for(int i = 0; i < n; i++){
        printf("%5d", a[i]);
    }
    
 }
   
  
