#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
int main(){
    int a[7]={0},tmp=0,n;
    char lotto[50]="lotto[0000";
    char last[50]="0]";
    FILE* counterbin;
   

    int arr_write[1]={1};
    int arr_read[1];
    if(counterbin=fopen("counter.bin","rb+")==NULL){
       counterbin= fopen("counter.bin","wb+");
       fwrite(arr_write,sizeof(int),1,counterbin);
    }else{
    fseek(counterbin,0,SEEK_SET);  
    fread(arr_write,sizeof(int),1,counterbin);
    arr_write[0]=arr_read[0]+1;
    fseek(counterbin,0,SEEK_SET);  
    fwrite(arr_write,sizeof(int),1,counterbin);
    }
    fseek(counterbin,0,SEEK_SET);
    fread(arr_read, sizeof(int),1,counterbin);
    fclose(counterbin);   
    
    
    if(arr_read[0]){
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
        } fprintf(fp,"======== csie@CGU =========\n");
        fclose(fp);
        
    }

