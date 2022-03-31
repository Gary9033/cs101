#include <stdio.h>
 int i=0;
int my_strlen(char *s){
   while(*(s+i)!=0){
       i++;
    }return i;  
}
int rec_strlen(char *s){
    if(*(s+i)==0){return i;}else{i++;};
    return rec_strlen(*(s+i)); 
}
char *my_sort(char *s){
    char tmp;
    s=sizeof(s);
    for(int n=0;n<s;n++){
        for(int i=0;i<n-1;i++){
        if(*s+i>*(s+(i+1))){
        tmp=*(s+(i+1));
        *(s+(i+1))=*s+i;
        *(s+i)=tmp;
        }
    }
    }return s;
}

int main()
{   char s[]="IU is a girl!";
    printf("len=%d\n",my_strlen(s));
    printf("len=%d\n",rec_strlen(s));
    printf("len=%s\n",mt_sort(s));
    return 0;
}
