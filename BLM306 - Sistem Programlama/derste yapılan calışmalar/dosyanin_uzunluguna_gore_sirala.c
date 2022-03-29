#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include"dllist.h"
int main(int argc, char **argv)
{
int i,exists;
struct stat buf;
DIR *d;
struct dirent *de;
Dllist tmp,files;
int maxlen;
d=opendir("/home/coder_xyz/");
if (d==NULL)
printf("Klasor hatali\n");
else{
maxlen=0;
files=new_dllist();
for (de=readdir(d);de!=NULL; de=readdir(d)){
dll_append(files,new_jval_s(strdup(de->d_name))); // 
if (strlen(de->d_name)>maxlen) maxlen=strlen(de->d_name); // her bir düðümün boyutunu kontrol ediyor 
}
closedir(d); // dirnet'i kapat

dll_traverse(tmp,files){
exists=stat(tmp->val.s,&buf); //tmp listenini içinde nesne ismini oku
if (exists<0) printf("hata \n");
else{
printf("   %*s :%ld   :%ld \n",-maxlen,tmp->val.s,buf.st_size,buf.st_ino);
}
}
}
return 0;

}
