#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
char buf1[]="first";
#define FILE_MODE 0644
int main(void)
{
     int fd;
     char buf[]="ABCDEFGHIJ";
     if((fd=creat("task2.txt",FILE_MODE))<0)
     {      printf("creat error\n");
            exit(1);
     }
     if(write(fd,buf1,10)!=10)
     {      printf("buf1 write error\n");
            exit(1);
     }
     close(fd);
     if((fd=open("task2.txt",O_RDWR|O_APPEND))==-1){
            printf("open error");
     }
     if(lseek(fd,0,SEEK_SET)==-1){
            printf("lseek error");
     }//��ΪO_APPEND����û�� 
     if(write(fd,buf,10)!=10){
            printf("write error");
     }
     close(fd);
     if((fd=open("task2.txt",O_RDWR|O_APPEND))==-1){
            printf("open error");
     }
     if((lseek(fd,0,SEEK_SET)==-1)){
            printf("lseek error");
     }//������ĩβ����lseek���ʼ�� 
     if(read(fd,buf,10)!=10){
            printf("read error");
     }
     close(fd);
     exit(0);
}
