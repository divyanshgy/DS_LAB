#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
int top=-1;
int stack[maxsize];
void push(int n){
if(top==maxsize-1)
    printf("Stack overflow");
else if(n>9){
    top=top+1;
    stack[top]=n+55;
}
else{
    top=top+1;
    stack[top]=n;
}
}
void pop(){
if(top==-1)
    printf("Underflow");
else if(stack[top]>9){
        printf("%c",stack[top]);
        }
        else{
        printf("%d",stack[top]);
        }
    top--;
}
int main(){
int num,base,rem;
printf("Enter the number and the base:");
scanf("%d%d",&num,&base);
while(num!=0){
    rem=num%base;
    push(rem);
    num=num/base;
}
while(top>=0){
    pop();
}
return 0;
}
