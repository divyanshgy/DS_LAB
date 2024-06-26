#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*link;
};
typedef struct node* NODE;

NODE Insert(NODE head, int data, int index){
    NODE HEAD=head;
    NODE newnode=(NODE)malloc(sizeof(struct node));
    for(int i=0;i<index-1;i++){
        HEAD=HEAD->link;
    }
    newnode->link=HEAD->link;
    newnode->data=data;
    HEAD->link=newnode;
    return head;
}
NODE Delete(NODE head,int index){
    NODE cur=head;
    NODE prev=NULL;
    for(int i=0;i<index;i++){
        prev=cur;
        cur=cur->link;
    }
    prev->link=cur->link;
    free(cur);
    printf("Deleted\n");
    return head;
}
NODE display(NODE head){
NODE HEAD=head;
while(HEAD!=NULL){
    printf("%d\t",HEAD->data);
    HEAD=HEAD->link;
}
return head;
}
NODE reverse(NODE head){
     //printf("%d\n",head);
    NODE prev=NULL;
    NODE cur=head;
    NODE next=NULL;
    while(cur!=NULL){
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    return prev;
    //printf("%d",head);
}
NODE sort(NODE head){
    NODE temp=NULL;

}

int main(){
int a,index,data;
NODE head=(NODE)malloc(sizeof(struct node));
NODE second=(NODE)malloc(sizeof(struct node));
NODE third=(NODE)malloc(sizeof(struct node));
NODE fourth=(NODE)malloc(sizeof(struct node));
NODE fifth=(NODE)malloc(sizeof(struct node));
head->data=1;
head->link=second;
second->data=2;
second->link=third;
third->data=3;
third->link=fourth;
fourth->data=4;
fourth->link=fifth;
fifth->data=5;
fifth->link=NULL;
while(1){
printf("CHOOSE:\ni) Insert an element before another element in the existing list\nii) Insert an element after another element in the existing list\niii) Delete a given element from the list\niv) Traverse the list\nv) Reverse the list");
scanf("%d",&a);
switch(a){
case 1:
    printf("\nEnter the element data and the index before where you want to insert:");
    scanf("%d%d",&data,&index);
    head=Insert(head,data,index);
    //display(head);
    break;
case 2:
    printf("Enter the element data and the index after where you want to insert:");
    scanf("%d%d",&data,&index);
    head=Insert(head,data,index+1);
    //display(head);
    break;
case 3:
    printf("Enter the index you want to delete:\n");
    scanf("%d",&index);
    head=Delete(head,index);
    break;
case 4:
    display(head);
    break;
case 5:
    head=reverse(head);
    break;
default:
    printf("Invalid");
    break;
}
}
}
