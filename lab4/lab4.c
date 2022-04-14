#include <stdio.h>
int find_n(int a[10],int j){
   for(int i=0;i<10;i++){
        if(a[i]==j){
            return i+1;
        }
    }
}

void j(){
    int n[10]={1,2,3,4,5,6,7,8,9,0};
    int num;
    int *p;
    scanf("%d",&num);
    int i=find_n(n,num);
    p=n+i-1;

    printf("&n[%d]->%i, n[%d]=%d;p->%i,*p=%d\n",i,n+i-1,i,num,p,*p);

}
void k(){
    int n[10]={1,2,3,4,5,6,7,8,9,0};
    int *ap[10];
    int tmp=0;
    for(int i = 9; i > 0; i--){
    for(int j = 0; j <= i-1; j++){
        if( *(n+j) > *(n+j+1)){
            tmp = *(n+j);
            *(n+j) = *(n+j+1);
            *(n+j+1) = tmp;
          }
        }
    }
    for(int i=0;i<10;i++){
            ap[i]=n+i;
            printf("&n[%d]->%p, n[%d] = %d,ap[%d]->%p, *ap[%d] = %d\n ", i, ap[i], i, *(ap[i]),i, ap[i], i, *(ap[i]));

    }



}
 int main(){
      printf("NO.1-------------------\n");
      j();
      printf("NO.2-------------------\n");
      k();
 }