#include <stdio.h>

struct book{
    int bookno;
    char bookname[100];
};
int main(){
    FILE *fp=fopen("kavy.txt","w+");
    printf("enter ");
    int a=2,i=0 ;
    struct book ptr[a],b[a];
    while(i<a){
       scanf("%d%s",&ptr[i].bookno,ptr[i].bookname);
       fwrite(&ptr[i],sizeof(struct book),1,fp);
       i++;
    }
    rewind(fp);
    i=0;
    while(i<a){
        fread(&b[i],sizeof(struct book),1,fp);
        printf("%d",b[i].bookno);
        i++;
    }
     return 0;
}