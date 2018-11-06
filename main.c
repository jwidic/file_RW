#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>


static int gene_filename(char *pFileName,const char *pFileType )
{
	time_t curTime = time(NULL);
	struct tm *sTm = localtime(&curTime);
	sprintf(pFileName,"%02d%02d%02d%02d%02d%02d",(sTm->tm_year-100),(sTm->tm_mon+1), sTm->tm_mday,sTm->tm_hour,sTm->tm_min,sTm->tm_sec);
	strcat(pFileName,pFileType);
	printf("pFileName %s size %d \n",pFileName, sizeof(pFileName));

	return 0;
}
void main(int argc,char *argv[]){
	mmcsd_record("./","aaaaaaaaaaaaa", 10,".txt");
}

int mmcsd_record( const char *pPath, const char *pData, const int iLen, const char *pFileType)
{

	int fd;
	int stat;
	char tFilePathName[100];
	char pFileName[20];
	gene_filename(pFileName,".txt");
	strcpy(tFilePathName,pPath);
	strcat(tFilePathName,pFileName);
	printf("the tFilePathName is %s \n",tFilePathName);


	fd=open(tFilePathName,O_RDWR | O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
	if(fd == -1){
		perror("open \n");
	}else{
		printf("file open successed %d\n", fd);
	}

	stat = write(fd,pData,iLen);
	if( stat == -1 ){
		perror("error");
	}else{
	 	printf("stat is %d write successed!the total \n", stat);
	}

	if(close(fd)== -1){
	 	printf("close \n");
	}else{
		printf("fd = %d file closed \n",fd);
	}
	return 0;

}
