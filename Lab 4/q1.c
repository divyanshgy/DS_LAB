#include<stdio.h>
#include<stdlib.h>
#define size 7
int items[size];
int front=-1,rear=-1;

void enqueue(int element){
if((front==rear+1) || (front==0&&rear==size-1)){
    printf("Queue is full,dequeing first element:");
    dequeue();
}
    if(front==-1){
       front=0;
       }
    rear=(rear+1)%size;
    items[rear]=element;

}
void dequeue(){
    int element;
    if(front==-1){
        printf("Queue is empty");
        exit(0);
    }
    else{
    element=items[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        printf("%d",front);
        front=(front+1)%size;
    }
    }
    printf("%d \n",element);
 }
int main(){
int a,i;
    for(i=0;i<10;i++){
    printf("Enter element:");
    scanf("%d",&a);
    enqueue(a);
    }

for(i=0;i<size;i++){
dequeue();
}
return 0;
}
