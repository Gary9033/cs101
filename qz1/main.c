#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int a[7]={0},tmp=0,counter;
    char lotto[50]="lotto[0000";
    char last[50]="0]";
    FILE* fp;
    fp=fopen("counter.bin","r");

    int arr_write[1]={1};
    int arr_read[1];
    if(fp==NULL){
     FILE* fp2= fopen("counter.bin","wb+");
       fwrite(arr_write,sizeof(int),1,fp2);
    }else{
      fclose(fp);
    }
    FILE *fp2=fopen("counter.bin","rb");
       fread(arr_read,sizeof(int),1,fp2);
       fclose(fp2);
       counter=arr_read[0];
    arr_write[0]=counter;
    FILE* fp2=fopen("counter.bin","wb");
    fwrite(arr_write,sizeof(int),1,fp2);
    fclose(fp2);
    



    FILE* fp3;
    fp=fopen("operator_id.bin","r");

    int arr_opwrite[1]={1},op;
    int arr_opread[1];
    scanf("%d",op);
    arr_opwrite[1]=op;
    if(fp3==NULL){
     FILE* fp3= fopen("operator_id.bin","wb+");
       fwrite(arr_opwrite,sizeof(int),1,fp3);
    }else{
      fclose(fp3);
    }
    FILE *fp3=fopen("operator_id.bin","rb");
       fread(arr_opread,sizeof(int),1,fp3);
       fclose(fp3);
       counter=arr_opread[0];
    arr_write[0]=counter;
    FILE* fp3=fopen("operator_id.bin","wb");
    fwrite(arr_opwrite,sizeof(int),1,fp2);
    fclose(fp3);
       
    
    if(counter){
      last[0]='arr_read[0]';
      strcat(lotto,last);
    }
    FILE *fp;
    
    fp=fopen(lotto,"w+");

   
    scanf("%d",&n);
   
    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=======+ No.%0*d =========\n",5,arr_write[0]);
    time_t curtime;
    time(&curtime);

    fprintf(fp,"= %.24s=\n",ctime(&curtime));

    for (int i=0;i<5;i++) {
        fprintf(fp,"[%d]: ",i+1);
        if (i<=(n-1)) {
            for (int i=0;i<6;i++) {
            a[i]=rand()%69+1;
            }
            a[6]=rand()%9+1;
            for (int i=0;i<6;i++) {
              for (int j=i+1;j<6;j++) {
                if (a[i]==a[j]) {
                a[j]=rand()%69+1;
                }
             }
           }
        for (int j=5;j>0;j--) {
        for (int k=0;k<=j-1;k++) {
            if (a[k]>a[k+1]) {
                tmp=a[k];
                a[k]=a[k+1];
                a[k+1]=tmp;
            }
          }
        }
        for (int i=0;i<7;i++) {
            if (a[i]<10) {
                fprintf(fp,"0%d ",a[i]);
            } else {fprintf(fp,"%d ",a[i]);
          }
         }
        fprintf(fp,"\n");
        } else {
        for (int i=0;i<7;i++) {
            fprintf(fp,"-- ");
        }
              fprintf(fp,"\n");
        }     tmp=0;
              for (int i=0;i<7;i++) {
                  a[i]=0;
                }
        } 
        fprintf(fp,"=======* Op.%0*d =========\n",5,arr_write[0]);
        fprintf(fp,"======== csie@CGU =========\n");
        fclose(fp);
        
    }
