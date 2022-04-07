#include<stdio.h>
#include<string.h>
void rec_dec(char *s){
  if(*s){
      printf("%c",*s++);
      printf(",");
      return rec_dec(s++);
    } printf("\n");
}

int hanoi_tower (int i){
    FILE* fp;
void hanoi (int num, char start, char temp, char end ){
   if( num > 0 ){
       hanoi ( num-1 , start , end , temp );
       fprintf(fp,"Move disk %d from %c to %c\n",num, start, end);
       hanoi ( num-1 , temp , start , end);
  }
}
 fp=fopen("hanoi.txt","w+");
 hanoi(4,'A','B','C');
 fclose(fp);
 return 0;
}
int multiplication(int i,int j){
    if (i<=9){
      if (j<=9){
          printf("%d*%d=%2d\t",i,j,i*j);
          multiplication(i,j+1);
      }else{
        printf("\n");
        i++;
        multiplication(i,1);
        }
    }
}
int main(){
    char s[]="1234567890";
    rec_dec(s);
    printf("func#1-----------------------\n");
    hanoi_tower (16);
    printf("func#2-----------------------\n");
    multiplication(1,1);
    printf("func#3-----------------------\n");
}
