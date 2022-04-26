#include <stdio.h>
#include <stdlib.h>
int *get_int_array(int n){
 
 int *ip=(int*)calloc(n,sizeof(int));
  return ip;
   
}
void set_value(int* p,int v){
    *p=v;
}
void print_array(int *p,int n){
    for(int i=1;i<=n;i++){
        if(i==1){
        printf("[%d,",*p+i);
       }else if(i==10){
        printf(" %d]",*p+i);    
       }else{
        printf(" %d,",*p+i);
    }
 }
}
int main(){
    int n=10;
    int * ip=get_int_array(n);
    for(int i=0;i<n;i++){
        set_value(ip+1,i+1);
    }
    printf("No.1-------------------");
    print_array(ip,n);
    
    free(ip);
    return 0;
}
