#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *get_int_array(int n){
    return (int*)calloc(n,sizeof(int));
}
void set_value(int *p,int v){
    *p=v;
}
void print_array(int *p,int n){
    int i=0;
    printf("[");
    while(i!=(n-1)){
    printf("%d,",*p+i);
     i++;    
    }
    printf("%d]",*p+i);
}
typedef struct arraylist{
    int n;
    int*(*fun1)(int);
    void(*fun2)(int*,int);
    void(*fun3)(int*,int);
}arraylist_t;
char* func(char *a,char *b){
    int len1=0,len2=0;
    while (*(a+len1) != '\0'){len1++;}
    while (*(b+len2) != '\0'){len2++;}
    int len3=len1+len2;
    char* New = calloc(len3+1, sizeof(char));
    for (int i=0; i<=len1; i++){*(New+i) = *(a+i);}
    for (int i=len1,y=0; i<len3; i++,y++){*(New+i) = *(b+y);}
    return New;
}
char* add_str_func(char* a,char* b,char* (*func)(char*,char*)){
    return func(a,b);
}
int main(){
    int n=10;
    arraylist_t all;
    all.n=20;
    all.fun1=get_int_array;
    all.fun2=set_value;
    all.fun3=print_array;
    int *ip=get_int_array(n);
    for(int i=0;i<n;i++){
        set_value(ip+i,i+1);
    }
    printf("No.1 -------------------\n");
    print_array(ip,n);
    printf("\n");
    printf("No.2 -------------------\n");
    all.fun3(ip,all.n); 
    printf("\n");
    free(ip);
    printf("No.3 -------------------\n");
    printf("%s",add_str_func("IU!IU!","@CGU",func));
    
    return 0;
}
