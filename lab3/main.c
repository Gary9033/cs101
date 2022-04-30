#include <stdio.h>

int my_strlen(char *s){
   if(*s==0)
     return 0;
    return 1+ my_strlen(++s);
}
int rec_strlen(char *s){
    int i=0;
    if(*(s+i)==0){return 0;}else{i++;}
    return 1+rec_strlen(s+i);
}
char *my_sort(char *s){
    char tmp;
    for(char* n=s;*n;n++){
        for(char* i=n+1;*i;i++){
        if(*n>*i){
        tmp=*n;
        *n=*i;
        *i=tmp;
        }
    }
    }return s;
}

int main()
{   char s[]="IU is a girl!";
    printf("len=%d\n",my_strlen(s));
    printf("len=%d\n",rec_strlen(s));
    printf("len=%s\n",my_sort(s));
    return 0;
}
