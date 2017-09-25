/*fifo_client*/
/*���ܣ������������ĵ���*/

#include <stdio.h>
#include <stdlib.h>

#define FILE "/tmp/myFile"/*�����ܵ���·�����ļ���*/ 

int main(int argc,char *argv[])
{
    FILE *fp;
	int i;
	
	if(argc<=1)
	{
		printf("usage: %s <message>\n",argv[0]);
		exit(1);
	}
	
	if((fp=fopen(FILE,"w"))==NULL)
	{
		printf("open FILE failed.\n");
		exit(1);
	} 
	
	for(i=argc-1;i>=1;i--)
	{
		if(fputs(argv[i],fp)==EOF)
		{
			printf("write FILE error.\n");
			exit(1);
		}
		if(fputs(" ",fp)==EOF)
		{
			printf("write FILE error.\n");
			exit(1);
		}
	}
	fclose(fp);
	return 0;
}
