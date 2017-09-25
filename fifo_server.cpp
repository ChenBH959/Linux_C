/*fifo_server*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>

#define FILE "/tmp/myFile" /*�����ܵ���·�����ļ���*/

int main()
{
	FILE *fp;
	char readbuf[80];

	if((fp=fopen(FILE,"r"))==NULL)/*��������ܵ��ļ������ڣ�Ҫ�ȴ���һ��*/
	{
		umask(0);//����ļ�����ʱȨ��λ����������
		mknod(FILE,S_IFIFO|0666,0);//����FIFO�ļ�
		printf("create new fifo successed. \n");
	}
	else
 		fclose(fp);

	while(1)
	{
		if((fp=fopen(FILE,"r"))==NULL)/*�������ܵ��ļ�*/	
 		{
			printf("open FILE failed. \n");
			exit(1);
		}

		if(fgets(readbuf,80,fp)!=NULL)/*�������ܵ��ļ��ж�����*/
		{
			printf("Received string :%s \n", readbuf);
			fclose(fp);
		}
		else
		{
			if(ferror(fp))
			{
				printf("read FILE failed.\n");
				exit(1);
			}
		}
	}
	return 0;
}

