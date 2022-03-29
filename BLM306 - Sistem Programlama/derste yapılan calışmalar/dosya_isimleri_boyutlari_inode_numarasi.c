#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc, char **argv)
{
int i,fd;
struct stat buf;
DIR *d;
struct dirent *de;
d=opendir("/home/coder_xyz/");
if (d==NULL)
printf("Klasör hatalı\n");
else
{

for (de=readdir(d);de!=NULL; de=readdir(d))
{
fd=stat(de->d_name,&buf);
if (fd<0) printf("hata \n");
else
{
printf("---%ld B : %s    :%ld \n",buf.st_size,de->d_name,buf.st_ino);
}
}
}
closedir(d);
return 0;
}
