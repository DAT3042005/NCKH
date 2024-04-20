#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *f1,*f2;
	//clrscr();
	f1=fopen("D:\\Baihat.txt","rt");
	f2=fopen("D:\\Baica.txt","wt");
	if(f1!=NULL && f2!=NULL )
	{
		int ch=fgetc(f1);
		while (! feof (f1))
	{
		fputc (ch,f2);
		ch=fgetc(f1);
		
	}
		fclose(f1);
    	fclose(f2);
}
	getch();
	return 0;
	
}




