#include <stdio.h>
int find_n(int a[10],int j){
   for(int i=0;i<10;i++){
        if(a[i]==j){
            return i;
        }
    }
}

void j(){
    int n[10]={1,2,5,4,3,6,7,8,9,0};
    int num;
    int *p;
    scanf("%d",&num);
    int i=find_n(n,num);
    p=n+i;

    printf("&n[%d]->%p, n[%d]=%d;p->%p,*p=%d\n",i,n+i,i,num,p,*p);
}
void k(){
    int n[10]={6,4,7,2,0,9,8,1,5,3};
    int *ap[10];
    int m[10]={0};
    for(int i=0;i<10;i++){
        m[i]=n[i];
    }
    int tmp;
    for(int j=10;j>0;j--){
        for(int i=0;i<j;i++){
            if(m[i+1]<m[i]){
              tmp =m[i+1];
              m[i+1]=m[i];
              m[i]=tmp;
            }
        }
    }
    for(int i=0;i<10;i++){
        int loc=find_n(n,m[i+1]);
        ap[i]=n+loc;
        printf("&n[%d]->%p, n[%d]=%d ;ap[%d]->%p,*ap[%d]=%d\n",loc,n+loc,loc,n[loc],i,ap[i],i,*(ap[i]));
    }

}
 int main(){
      printf("NO.1-------------------\n");
      j();
      printf("NO.2-------------------\n");
      k();
 }
