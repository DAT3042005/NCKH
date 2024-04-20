#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *f;//clrscr();
	f=fopen("D:\\Baihat.txt","r+");
	
	if(f!=NULL)
	{
	fputs("Em oi Ha Noi pho.\n",f);
	fputs("Ta con em ,mui hoang lan;ta con em ,mui hoa sua.",f);
	fclose(f);	
	}	
    geetch();
	return 0;
	
}


