#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next_node;
}node_t;
node_t* allocate_node(int data){
    node_t* p=(node_t*)calloc(1,sizeof(node_t)); 
    p->data=data;
    p->next_node=NULL;
    return p;
}
void show_list(node_t* head){
   while(head){
        printf("[%d]->",head->data); 
        head=head->next_node;
    }   
    printf("null\n");
}
node_t* append_node(node_t* head,int new_data){
   node_t* new_node=allocate_node(new_data);
   if(head){
       node_t* p=head;//把head複製一份給p，(這裡沒有碰到head)
       while(p->next_node){
           p=p->next_node; //為了找list的最後一個，NULL的前一個會停
       }
       p->next_node=new_node;//下一個(next_node)把NULL改成new_node
   }
   else {   //這裡才有弄到head
       head=new_node;
    }
    return head;
}
void free_all_node(node_t* head){
    node_t *p=NULL;
    while(head){
        p=head;
        head=head->next_node;
        printf("free([%d])->",p->data); 
        free(p);
    }   
    printf("null\n");
}
node_t* add_node(node_t* head,int new_data){
    node_t* p=allocate_node(new_data);
    p->next_node=head;
    return p;//把p變成head
}
node_t* del_node(node_t* head,int n){
   node_t* temp=head;
   for(int i=0;i<n-1;i++)
        {
            temp=temp->next_node;
        }
        node_t *del =temp->next_node;       
        temp->next_node=temp->next_node->next_node;
        del->next_node=NULL;
        free(del);                          
    }

int main(){ 
    node_t* head=NULL;
    head=append_node(head,0);
    show_list(head);
    head=append_node(head,1);
    show_list(head);
    head=add_node(head,-1);
    show_list(head);
    del_node(head,1);
    show_list(head);
    free_all_node(head);
    return 0;
}
