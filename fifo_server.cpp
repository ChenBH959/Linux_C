/*fifo_server*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>

#define FILE "/tmp/myFile" /*命名管道的路径、文件名*/

int main()
{
	FILE *fp;
	char readbuf[80];

	if((fp=fopen(FILE,"r"))==NULL)/*如果命名管道文件不存在，要先创建一个*/
	{
		umask(0);//清除文件创建时权限位的屏蔽作用
		mknod(FILE,S_IFIFO|0666,0);//创建FIFO文件
		printf("create new fifo successed. \n");
	}
	else
 		fclose(fp);

	while(1)
	{
		if((fp=fopen(FILE,"r"))==NULL)/*打开命名管道文件*/	
 		{
			printf("open FILE failed. \n");
			exit(1);
		}

		if(fgets(readbuf,80,fp)!=NULL)/*从命名管道文件中读数据*/
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

