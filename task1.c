#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 
char buf1[]="HelloNihao";
char buf2[]="HelloNihao";
char buf3[10];
//buf3 is used for containing the read string
#define FILE_MODE 0644 
int main(void)
 {
     int fd1;
     int fd2;
 
     if ((fd1=open("file.1",O_RDWR|O_CREAT,0))==-1) {
         printf("open error\n");
         exit(1);
     }
     if ((fd2=creat("file.2",O_RDWR|O_CREAT,0))==-1) {
         printf("open error\n");
         exit(1);
     }
 
     if (write(fd1,buf1,10)!=10) {
         printf("buf1 write error\n");
         exit(1);
     }
     if (write(fd2,buf2,10)!=10) {
         printf("buf2 write error\n");
         exit(1);
     }
 
     if (lseek(fd2,0,SEEK_SET)==-1) {//����Ƶ�file2�ļ���ʼ�ط� 
         printf("lseek error\n");
         exit(1);
     }
     if (read(fd2,buf3,10)==-1) {
        printf("file2 get error\n");
         exit(1);
     }
     if (lseek(fd1,0,SEEK_END)==-1) {//����Ƶ�file1�ļ�ĩβ�ط� 
         printf("lseek error\n");
         exit(1);
     }
     if (write(fd1,buf3,10)!=10) {
         printf("buf3 write error\n");
         exit(1);
     }
     exit(0);
}
