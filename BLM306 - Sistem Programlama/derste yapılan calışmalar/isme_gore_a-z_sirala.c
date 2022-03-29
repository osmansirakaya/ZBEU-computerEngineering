#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include"jrb.h"
#include"jval.h"
int main(int argc, char **argv)
{
int i,exists;
struct stat buf;
DIR *d;
struct dirent *de;
JRB tmp,files; // jrb tipinde 
int maxlen;

d=opendir(".");
if (d==NULL)
printf("Klasor hatali\n");
else{
maxlen=0;
files=make_jrb();
for (de=readdir(d);de!=NULL; de=readdir(d)){
jrb_insert_str(files,strdup(de->d_name),JNULL);
if (strlen(de->d_name)>maxlen) maxlen=strlen(de->d_name);
}
closedir(d);
jrb_traverse(tmp,files){
exists=stat(tmp->key.s,&buf);
if (exists<0) printf("hata \n");
else{
printf("   %*s :%ld   :%ld \n",-maxlen,tmp->key.s,buf.st_size,buf.st_ino);
	}
  } 
}
return 0;

}
